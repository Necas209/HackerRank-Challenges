import math
from dataclasses import dataclass
from typing import Self


@dataclass
class Points:
    x: float
    y: float
    z: float

    def __sub__(self, other: Self) -> Self:
        return Points(self.x - other.x, self.y - other.y, self.z - other.z)

    def dot(self, other: Self) -> float:
        return self.x * other.x + self.y * other.y + self.z * other.z

    def cross(self, other: Self) -> Self:
        return Points(self.y * other.z - self.z * other.y,
                      self.z * other.x - self.x * other.z,
                      self.x * other.y - self.y * other.x)

    def absolute(self: Self) -> float:
        return math.sqrt(self.dot(self))


def main() -> None:
    a = list(map(float, input().split()))
    b = list(map(float, input().split()))
    a = Points(a[0], a[1], a[2])
    b = Points(b[0], b[1], b[2])
    print(round(math.degrees(math.acos(a.dot(b) / (a.absolute() * b.absolute())))), chr(176), sep='')


if __name__ == '__main__':
    main()
