
#[macro_export]
macro_rules! polo_log (
    ($($arg:tt)+) => {
        if crate::db::SHOULD_LOG.load(std::sync::atomic::Ordering::SeqCst) {
            eprintln!($($arg)*);
        }
    }
);

#[macro_export]
macro_rules! try_unwrap_document {
    ($op_name:tt, $doc:expr) => {
        match $doc {
            Bson::Document(doc) => doc,
            t => {
                let name = format!("{}", t);
                let err = mk_field_name_type_unexpected($op_name.into(), "Document".into(), name);
                return Err(err);
            },
        }
    };
}

#[macro_export]
macro_rules! try_unwrap_array {
    ($op_name:tt, $arr:expr) => {
        match $arr {
            Bson::Array(arr) => arr,
            t => {
                let name = format!("{}", t);
                let err = mk_field_name_type_unexpected($op_name.into(), "Array".into(), name);
                return Err(err);
            },
        }
    };
}

