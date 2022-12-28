#!/usr/bin/env sh

curl --proto '=https' --tlsv1.2 https://sh.rustup.rs -sSf | sh
rustup update
echo "Rust version: " && rustc --version
