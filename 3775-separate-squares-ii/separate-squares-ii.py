from typing import List

class SegTree:
    def __init__(self, xs: List[int]):
        self.xs = xs
        self.n = len(xs) - 1  # number of elementary segments
        size = 4 * self.n if self.n > 0 else 4
        self.cov = [0] * size
        self.length = [0] * size

    def _pull(self, idx: int, l: int, r: int):
        if self.cov[idx] > 0:
            self.length[idx] = self.xs[r] - self.xs[l]
        else:
            if r - l == 1:
                self.length[idx] = 0
            else:
                self.length[idx] = self.length[idx * 2] + self.length[idx * 2 + 1]

    def _update(self, idx: int, l: int, r: int, ql: int, qr: int, delta: int):
        if qr <= l or r <= ql:
            return
        if ql <= l and r <= qr:
            self.cov[idx] += delta
            self._pull(idx, l, r)
            return
        mid = (l + r) // 2
        self._update(idx * 2, l, mid, ql, qr, delta)
        self._update(idx * 2 + 1, mid, r, ql, qr, delta)
        self._pull(idx, l, r)

    def update(self, ql: int, qr: int, delta: int):
        if ql >= qr or self.n <= 0:
            return
        self._update(1, 0, self.n, ql, qr, delta)

    def total_len(self) -> int:
        return self.length[1]


class Solution:
    def separateSquares(self, squares: List[List[int]]) -> float:
        # Build events and x-coordinates
        events = []
        xs = []
        for x, y, l in squares:
            x1, x2 = x, x + l
            y1, y2 = y, y + l
            xs.append(x1)
            xs.append(x2)
            events.append((y1, +1, x1, x2))
            events.append((y2, -1, x1, x2))

        xs = sorted(set(xs))
        # Map x to compressed index
        x_index = {v: i for i, v in enumerate(xs)}

        # Sort events by y
        events.sort()

        seg = SegTree(xs)

        # Sweep: record slabs (y_start, y_end, L, area_before)
        slabs = []
        area = 0  # exact integer union area accumulated below current y
        i = 0
        m = len(events)
        prev_y = events[0][0]

        # Apply all events at the first y to activate intervals for the first slab
        while i < m and events[i][0] == prev_y:
            _, typ, x1, x2 = events[i]
            seg.update(x_index[x1], x_index[x2], typ)
            i += 1

        while i < m:
            y = events[i][0]
            dy = y - prev_y
            L = seg.total_len()
            if dy > 0:
                slabs.append((prev_y, y, L, area))
                area += L * dy

            # process all events at this y
            while i < m and events[i][0] == y:
                _, typ, x1, x2 = events[i]
                seg.update(x_index[x1], x_index[x2], typ)
                i += 1

            prev_y = y

        total = area  # total union area (integer)

        # We need minimal Y where below(Y) == total/2.
        # Use doubled areas to avoid floating comparisons:
        target2 = total  # represents 2 * (total/2)

        # If total == 0 (shouldn't happen with li>=1), return 0.0 safely.
        if total == 0:
            return 0.0

        for y1, y2, L, area_before in slabs:
            area_before2 = area_before * 2
            slab_gain2 = 2 * L * (y2 - y1)

            if target2 <= area_before2:
                return float(y1)

            if target2 <= area_before2 + slab_gain2:
                if L == 0:
                    # area doesn't change in this slab; only possible if exactly on boundary
                    return float(y1)
                # Solve: area_before2 + 2*L*(Y - y1) = target2
                return y1 + (target2 - area_before2) / (2.0 * L)

        # If not found inside slabs, it must be at/above the topmost edge
        return float(prev_y)
