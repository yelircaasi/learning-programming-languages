#!/usr/bin/env sh

cd hello_cargo
cargo build
./target/debug/hello_cargo

echo "" && echo "------------------------" && echo ""

cargo run

echo "" && echo "------------------------" && echo ""

cargo check
