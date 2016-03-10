#include "ruby.h"
#include <sys/statvfs.h>

VALUE Statvfs = Qnil;

void Init_statvfs();

// Prototype for get_statvfs
VALUE get_statvfs(VALUE self, VALUE path);

void Init_statvfs() {
	Statvfs = rb_define_module("Statvfs");
	rb_define_method(Statvfs, "get_statvfs", get_statvfs, 1);	
}

// 'get_statvfs' method.
VALUE get_statvfs(VALUE self, VALUE path) {
	struct statvfs info;
    statvfs (StringValuePtr(path), &info);
        
    VALUE result = rb_hash_new();
    // file system block size
    rb_hash_aset(result, rb_str_new2("f_bsize"), LONG2NUM(info.f_bsize));
    // fragment size
    rb_hash_aset(result, rb_str_new2("f_frsize"), LONG2NUM(info.f_frsize));
    // size of fs in f_frsize units
    rb_hash_aset(result, rb_str_new2("f_blocks"), LONG2NUM(info.f_blocks));
    // free blocks
    rb_hash_aset(result, rb_str_new2("f_bfree"), LONG2NUM(info.f_bfree));
    // free blocks for unprivileged users
    rb_hash_aset(result, rb_str_new2("f_bavail"), LONG2NUM(info.f_bavail));
    // inodes
    rb_hash_aset(result, rb_str_new2("f_files"), LONG2NUM(info.f_files));
    // free inodes
    rb_hash_aset(result, rb_str_new2("f_ffree"), LONG2NUM(info.f_ffree));
    // free inodes for unprivileged users
    rb_hash_aset(result, rb_str_new2("f_favail"), LONG2NUM(info.f_favail));
    // file system ID
    rb_hash_aset(result, rb_str_new2("f_fsid"), LONG2NUM(info.f_fsid));
    // mount flags
    rb_hash_aset(result, rb_str_new2("f_flag"), LONG2NUM(info.f_flag));
    // maximum filename length
    rb_hash_aset(result, rb_str_new2("f_namemax"), LONG2NUM(info.f_namemax));
    
    return result;
}
