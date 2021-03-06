/* SPDX-License-Identifier: LGPL-2.1+ */
#pragma once

/***
  This file is part of systemd.

  Copyright 2010-2012 Lennart Poettering
  Copyright 2010-2012 Kay Sievers
***/

enum {
        CONF_FILES_EXECUTABLE    = 1U << 0,
        CONF_FILES_REGULAR       = 1U << 1,
        CONF_FILES_DIRECTORY     = 1U << 2,
        CONF_FILES_BASENAME      = 1U << 3,
        CONF_FILES_FILTER_MASKED = 1U << 4,
};

int conf_files_list(char ***ret, const char *suffix, const char *root, unsigned flags, const char *dir, ...);
int conf_files_list_strv(char ***ret, const char *suffix, const char *root, unsigned flags, const char* const* dirs);
int conf_files_list_nulstr(char ***ret, const char *suffix, const char *root, unsigned flags, const char *dirs);
int conf_files_insert(char ***strv, const char *root, char **dirs, const char *path);
int conf_files_insert_nulstr(char ***strv, const char *root, const char *dirs, const char *path);
int conf_files_list_with_replacement(
                const char *root,
                char **config_dirs,
                const char *replacement,
                char ***files,
                char **replace_file);
int conf_files_cat(const char *root, const char *name);
