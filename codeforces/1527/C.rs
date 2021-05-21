use std::collections::HashMap;
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
  let out = &mut BufWriter::new(stdout());

  let t: i32 = scan.next();
  for _ in 0..t {
    let n: usize = scan.next();
    let a: Vec<i64> = (0..n).map(|_| scan.next()).collect();
    let mut cache: HashMap<i64, i64> = HashMap::new();
    let mut ans: i64 = 0;

    for i in 0..n {
      let val: i64 = a[i];
      let count = cache.entry(val).or_insert(0i64);
      ans += *count * (n as i64 - i as i64);
      *count += i as i64 + 1;
    }

    writeln!(out, "{}", ans).ok();
  }
}
