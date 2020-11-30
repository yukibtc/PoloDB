#include "utils.h"

int JsIsInteger(napi_env env, napi_value value) {
  napi_status status;
  napi_value global;

  status = napi_get_global(env, &global);
  CHECK_STAT(status);

  napi_value number_instance;
  status = napi_get_named_property(env, global, "Number", &number_instance);
  CHECK_STAT(status);

  napi_value is_int_fun;
  status = napi_get_named_property(env, number_instance, "isInteger", &is_int_fun);
  CHECK_STAT(status);

  size_t argc = 1;
  napi_value argv[] = { value };

  napi_value result;
  status = napi_call_function(env, number_instance, is_int_fun, argc, argv, &result);
  CHECK_STAT(status);

  bool bl_result = false;

  status = napi_get_value_bool(env, result, &bl_result);
  CHECK_STAT(status);

  return bl_result ? 1 : 0;
}

napi_status JsIsArray(napi_env env, napi_value value, bool* result) {
  napi_status status;
  napi_value global;

  status = napi_get_global(env, &global);
  CHECK_STAT(status);

  napi_value array_obj;
  status = napi_get_named_property(env, global, "Array", &array_obj);
  CHECK_STAT(status);

  napi_value is_array_fun;
  status = napi_get_named_property(env, array_obj, "isArray", &is_array_fun);
  CHECK_STAT(status);

  size_t argc = 1;
  napi_value argv[] = { value };

  napi_value js_result;

  status = napi_call_function(env, array_obj, is_array_fun, argc, argv, &js_result);
  if (status != napi_ok) {
    return status;
  }

  status = napi_get_value_bool(env, js_result, result);
  CHECK_STAT(status);

  return napi_ok;
}
