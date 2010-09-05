LOCAL_PATH:= $(call my-dir)

include $(CLEAR_VARS)
LOCAL_SRC_FILES:= logwrapper.c
LOCAL_MODULE := logwrapper
LOCAL_STATIC_LIBRARIES := liblog libc
LOCAL_MODULE_PATH := $(TARGET_ROOT_OUT_SBIN)
LOCAL_UNSTRIPPED_PATH := $(TARGET_ROOT_OUT_SBIN_UNSTRIPPED)
LOCAL_FORCE_STATIC_EXECUTABLE := true
include $(BUILD_EXECUTABLE)

SYMLINKS := $(TARGET_OUT)/bin/logwrapper
$(SYMLINKS): $(LOCAL_INSTALLED_MODULE)
	@echo "Symlink: $@ -> /sbin/logwrapper"
	@mkdir -p $(dir $@)
	@rm -rf $@
	$(hide) ln -sf /sbin/logwrapper $@

ALL_DEFAULT_INSTALLED_MODULES += $(SYMLINKS)
