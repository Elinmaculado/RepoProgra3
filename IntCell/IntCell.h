#ifndef INTCELL_H
#define INTCELL_H

class IntCell {
public:
    explicit IntCell(int newValue = 0);
    IntCell(const IntCell &rhs);
    IntCell(IntCell &&rhs) noexcept;
    ~IntCell() = default;

    IntCell &operator=(const IntCell &rhs);
    IntCell &operator=(IntCell &&rhs) noexcept;

    // Overloaded assignment operator to accept primitive int
    IntCell &operator=(int rhs);

    int getValue() const;
    void setValue(int newValue);

private:
    int storedValue;
};

#endif  // INTCELL_H