/*
 * dinghy.c
 * Copyright (C) 2018 Igalia S.L.
 *
 * Distributed under terms of the MIT license.
 */

#include <stdlib.h>
#include <wpe/webkit-web-extension.h>

static void
on_web_page_created (WebKitWebExtension *extension,
                     WebKitWebPage      *page,
                     void               *user_data)
{
    /*
     * In the future, we might want to do something interesting here.
     * Currently, we just print something to show that we have the
     * ability to code in the web process.
     */
    if (g_getenv ("DINGHY_WEB_EXTENSION_DEMO"))
        g_message ("Created page #%" G_GUINT64_FORMAT, webkit_web_page_get_id (page));
}

G_MODULE_EXPORT void
webkit_web_extension_initialize (WebKitWebExtension *extension)
{
    g_signal_connect (extension, "page-created",
                      G_CALLBACK (on_web_page_created), NULL);
}
