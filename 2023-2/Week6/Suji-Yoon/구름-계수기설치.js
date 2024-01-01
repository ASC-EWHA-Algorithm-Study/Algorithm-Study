// 단순 구현
const solution = (N, A, B, K) => {
  let cnt = 0;
  while (cnt < K) {
    update(A, B, N);
    cnt += 1;
  }
  console.log(B.join(''))
};

const update = (A, B, N) => {
  let idx = N - 1;
  while (idx > -1) {
    if (B[idx] + 1 > A[idx]) {
      B[idx] = 0;
      idx -= 1;
    } else {
      B[idx] += 1;
      return;
    }
  }
};

const readline = require("readline");

(async () => {
  let rl = readline.createInterface({ input: process.stdin });
  let N = null;
  let A = null;
  let B = null;
  let K = null;

  for await (const line of rl) {
    if (!N) {
      N = +line;
    } else if (!A) {
      A = line.split(" ").map((el) => +el);
    } else if (!B) {
      B = line.split(" ").map((el) => +el);
    } else {
      K = +line;
      rl.close();
    }
  }

  solution(N, A, B, K);
  process.exit();
})();
