use std::io::{stdin, stdout, BufWriter, Write};
#[derive(Default)]
struct Scanner {
  buffer: Vec<String>,
}
impl Scanner {
  fn next<T: std::str::FromStr>(&mut self) -> T {
    loop {
      if let Some(token) = self.buffer.pop() {
        return token.parse().ok().expect("Failed parse");
      }
      let mut input = String::new();
      stdin().read_line(&mut input).expect("Failed read");
      self.buffer = input.split_whitespace().rev().map(String::from).collect();
    }
  }
}

fn main() {
  let mut scan = Scanner::default();

  let t: i32 = scan.next();
  for _ in 0..t {
    let n: i64 = scan.next();
    for i in 0..45 {
      let k: i64 = (1i64 << i) - 1;
      if k >= n {
        println!("{}", k >> 1);
        break;
      }
    }
  }
}
