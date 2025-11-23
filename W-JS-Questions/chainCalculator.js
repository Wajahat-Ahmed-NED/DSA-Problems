// Chain Calculator

class ChainCalculator {
    constructor(value = 0) {
        this.value = value;
    }

    add(num) {
        this.value += num;
        return this;
    }
    subtract(num) {
        this.value -= num;
        return this;
    }
    mutliply(num) {
        this.value *= num;
        return this;
    }
    divide(num) {
        if (num == 0) throw new Error("Cannot divide by zero");
        this.value /= num;
        return this;
    }

    getResult() {
        return this.value;
    }
}

const result = new ChainCalculator(5)
    .add(10)
    .subtract(3)
    .mutliply(4)
    .divide(2)
    .getResult();

console.log(result); //24