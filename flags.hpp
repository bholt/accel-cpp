#pragma once

#define DECLARE_FLAG(type, name) namespace flags { extern type name; }
#define DEFINE_FLAG(type, name, default_val, description) namespace flags { type name = default_val; }
