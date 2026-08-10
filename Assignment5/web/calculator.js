function* calc(initialValue) {
    let result = initialValue;

    while (true) {
        const input = yield result;

        // Validate input
        if (
            !input ||
            typeof input.operation !== "string" ||
            typeof input.value !== "number"
        ) {
            yield "Invalid input";
            continue;
        }

        const { operation, value } = input;

        switch (operation) {
            case "add":
                result += value;
                break;

            case "subtract":
                result -= value;
                break;

            case "multiply":
                result *= value;
                break;

            case "divide":
                if (value === 0) {
                    yield "Cannot divide by zero";
                    continue;
                }
                result /= value;
                break;

            default:
                yield "Invalid operation";
                continue;
        }

        yield result;
    }
}

const c = calc(50);

console.log(c.next()); 
// 50

console.log(c.next({ operation: "add", value: 30 }));
// 80

console.log(c.next({ operation: "multiply", value: 2 }));
// 160

console.log(c.next({ operation: "add", value: "30" }));
// "Invalid input"

console.log(c.next({ operation: "multiply", value: 0 }));
// 0