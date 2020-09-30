// by Alexander Nikolskiy

const readline = require('readline');
const rl = readline.createInterface({
    input: process.stdin,
    terminal: false
});

process.stdin.setEncoding('utf8');
rl.once('line', () => {
    rl.on('line', readLine);
});

function readLine (line) {
    const arr = line.toString().split(' ').map(Number);

    console.log(max(arr));
    process.exit();
}

function max(numbers) {
  const n = numbers.length;
  let first = 0;
  let second = 0;

  for (let x = 0; x < n; ++x) {
      if(numbers[x] >= first) {
          second = first;
          first = numbers[x];
      } else if(numbers[x] > second) {
          second = numbers[x];
      }
  }

  return (first * second);
}

module.exports = max;