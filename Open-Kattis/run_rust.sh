cp $1 src/bin
cargo run --bin ${1%.rs}
