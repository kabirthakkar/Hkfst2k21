//HACKTOBERFEST 2021
//RUN THIS ON BROWSER CONSOLE OR ADDON an HTML
const checkPrimeNumber = (number)=>{
    if (number > 1) {
    for (let i = 2; i < number; i++) {
        if (number % i == 0) {
            isPrime = false;
            break;
        }
    }

    if (isPrime) {
        console.log(`${number} is a prime number`);
    } else {
        console.log(`${number} is a not prime number`);
    }
}
else {
    console.log("The number is not a prime number.");
}}


const number = parseInt(prompt("Enter a positive number: "));
let isPrime = true;
const isOne = (number == 1) ? console.log(`${number} is not a prime number`) : checkPrimeNumber(number) 