#include "ngx_http_autols_module.h"

static ngx_command_t ngx_http_autols_commands[] = {
	{ngx_string("autols"),
	NGX_HTTP_MAIN_CONF | NGX_HTTP_SRV_CONF | NGX_HTTP_LOC_CONF | NGX_CONF_FLAG,
	ngx_conf_set_flag_slot,
	NGX_HTTP_LOC_CONF_OFFSET,
	offsetof(ngx_http_autols_loc_conf_t, enable),
	NULL},

	{ngx_string("autols_print_debug"),
	NGX_HTTP_MAIN_CONF | NGX_HTTP_SRV_CONF | NGX_HTTP_LOC_CONF | NGX_CONF_FLAG,
	ngx_conf_set_flag_slot,
	NGX_HTTP_LOC_CONF_OFFSET,
	offsetof(ngx_http_autols_loc_conf_t, printDebug),
	NULL},

	{ngx_string("autols_template_path"),
	NGX_HTTP_MAIN_CONF | NGX_HTTP_SRV_CONF | NGX_HTTP_LOC_CONF | NGX_CONF_TAKE1,
	ngx_conf_set_str_slot,
	NGX_HTTP_LOC_CONF_OFFSET,
	offsetof(ngx_http_autols_loc_conf_t, patternPath),
	NULL},

	{ngx_string("autols_ignores"),
	NGX_HTTP_MAIN_CONF | NGX_HTTP_SRV_CONF | NGX_HTTP_LOC_CONF | NGX_CONF_1MORE,
	ngx_conf_autols_set_regex_then_string_array_slot,
	NGX_HTTP_LOC_CONF_OFFSET,
	offsetof(ngx_http_autols_loc_conf_t, entryIgnores),
	NULL},

	{ngx_string("autols_sections"),
	NGX_HTTP_MAIN_CONF | NGX_HTTP_SRV_CONF | NGX_HTTP_LOC_CONF | NGX_CONF_1MORE,
	ngx_conf_autols_set_str_array_slot,
	NGX_HTTP_LOC_CONF_OFFSET,
	offsetof(ngx_http_autols_loc_conf_t, sections),
	NULL},

	{ngx_string("autols_variables"),
	NGX_HTTP_MAIN_CONF | NGX_HTTP_SRV_CONF | NGX_HTTP_LOC_CONF | NGX_CONF_1MORE,
	ngx_conf_autols_set_keyval_array_slot,
	NGX_HTTP_LOC_CONF_OFFSET,
	offsetof(ngx_http_autols_loc_conf_t, keyValuePairs),
	NULL},

	{ngx_string("autols_local_time"),
	NGX_HTTP_MAIN_CONF | NGX_HTTP_SRV_CONF | NGX_HTTP_LOC_CONF | NGX_CONF_FLAG, 
	ngx_conf_set_flag_slot,
	NGX_HTTP_LOC_CONF_OFFSET,
	offsetof(ngx_http_autols_loc_conf_t, localTime),
	NULL},

	ngx_null_command
};

static ngx_http_module_t  ngx_http_autols_module_ctx = {
	NULL,                              /* preconfiguration */
	ngx_http_autols_init,              /* postconfiguration */

	ngx_http_autols_create_main_conf,  /* create main configuration */
	ngx_http_autols_init_main_conf,   /* init main configuration */

	NULL,                              /* create server configuration */
	NULL,                              /* merge server configuration */

	ngx_http_autols_create_loc_conf,   /* create location configuration */
	ngx_http_autols_merge_loc_conf     /* merge location configuration */
};

ngx_module_t  ngx_http_autols_module = {
	NGX_MODULE_V1,
	&ngx_http_autols_module_ctx,       /* module context */
	ngx_http_autols_commands,          /* module directives */
	NGX_HTTP_MODULE,                   /* module type */
	NULL,                              /* init master */
	NULL,                              /* init module */
	NULL,                              /* init process */
	NULL,                              /* init thread */
	NULL,                              /* exit thread */
	NULL,                              /* exit process */
	NULL,                              /* exit master */
	NGX_MODULE_V1_PADDING
};
