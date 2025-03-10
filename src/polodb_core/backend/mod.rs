
mod backend;

#[cfg(not(target_arch = "wasm32"))]
pub(crate) mod file;

pub(crate) mod memory;

pub(crate) use backend::{Backend, AutoStartResult};
