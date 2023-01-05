from dataclasses import dataclass

from typing_extensions import Self


@dataclass
class Complex:
    real: float
    imaginary: float

    def __init__(self, real: float, imaginary: float):
        self.real = real
        self.imaginary = imaginary
        self.complex = complex(self.real, self.imaginary)

    def __add__(self, no: Self) -> Self:
        comp = self.complex + no.complex
        return Complex(comp.real, comp.imag)

    def __sub__(self, no: Self) -> Self:
        comp = self.complex - no.complex
        return Complex(comp.real, comp.imag)

    def __mul__(self, no: Self) -> Self:
        comp = self.complex * no.complex
        return Complex(comp.real, comp.imag)

    def __truediv__(self, no: Self) -> Self:
        comp = self.complex / no.complex
        return Complex(comp.real, comp.imag)

    def mod(self) -> Self:
        return Complex(abs(self.complex), 0)

    def __str__(self) -> str:
        imag = self.imaginary if abs(self.imaginary) != 0 else 0
        sign = '+' if imag >= 0 else ''
        return f'{self.real:.2f}{sign}{imag:.2f}i'


def main() -> None:
    c = map(float, input().split())
    d = map(float, input().split())
    x = Complex(*c)
    y = Complex(*d)
    print(*map(str, [x + y, x - y, x * y, x / y, x.mod(), y.mod()]), sep='\n')


if __name__ == '__main__':
    main()
