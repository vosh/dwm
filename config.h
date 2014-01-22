/* See LICENSE file for copyright and license details. */

/* appearance */
static const char font[]            = "-*-Terminusmodx.Icons-medium-r-*-*-12-*-*-*-*-*-*-*";
static const char normbordercolor[] = "#9a7474";
static const char normbgcolor[]     = "#332d29";
static const char normfgcolor[]     = "#ededf7";
static const char selbordercolor[]  = "#9a7474";
static const char selbgcolor[]      = "#9a7474";
static const char selfgcolor[]      = "#ededf7";
static const unsigned int borderpx  = 1;        /* border pixel of windows */
static const unsigned int gappx     = 10;        /* gap pixel between windows */
static const unsigned int snap      = 32;       /* snap pixel */
static const unsigned int systrayspacing = 2;   /* systray spacing */
static const Bool showsystray       = True;     /* False means no systray */
static const Bool showbar           = True;     /* False means no bar */
static const Bool topbar            = True;     /* False means bottom bar */
static const Bool showtitle         = False;    /* True means show title in status bar */

/* tagging */
static const char *tags[] = { "Ñ main", "® web", "¨ files", "¸ ent", "½ term", " " };

static const Rule rules[] = {
	/* class      instance    title       tags mask     isfloating   monitor */
	{ "Gimp",     NULL,       NULL,       0,            True,        -1 },
	{ "urxvt",     NULL,       NULL,       0,            True,        -1 },
	{ "Iceweasel",  NULL,       NULL,       1 << 1,       False,       -1 },
	{ "Thunar",   NULL,       NULL,       1 << 2,       False,       -1 },
	{ "lowriter",   NULL,       NULL,       2 << 3,       False,       -1 },
	{ "mendeleydesktop",   NULL,       NULL,       2 << 3,       False,       -1 },
};

/* layout(s) */
static const float mfact      = 0.50; /* factor of master area size [0.05..0.95] */
static const int nmaster      = 1;    /* number of clients in master area */
static const Bool resizehints = False; /* True means respect size hints in tiled resizals */

static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "þ",      tile },    /* first entry is default */
	{ "ý",      NULL },    /* no layout function means floating behavior */
	{ "ÿ",      monocle },
};

/* key definitions */
#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static const char *dmenucmd[] = { "dmenu_run", "-fn", font, "-nb", normbgcolor, "-nf", normfgcolor, "-sb", selbgcolor, "-sf", selfgcolor, NULL };
static const char *termcmd[]  = { "urxvt", NULL };
static const char *filecmd[]  = { "thunar", NULL };
static const char *webcmd[]  = { "firefox", NULL };
static const char *scrot[]            = { "scrot", NULL };
static const char *initscreen[]            = { "initscreen", NULL };
static const char *mute[]             = { "amixer", "-q", "set", "Master", "toggle", NULL };
static const char *volumedown[]       = { "amixer", "-q", "set", "Master", "5%-", "unmute", NULL };
static const char *volumeup[]         = { "amixer", "-q", "set", "Master", "5%+", "unmute", NULL };

static Key keys[] = {
	/* modifier                     key        function        argument */
	{ Mod1Mask,                     XK_s,      spawn,          {.v = scrot } },
	{ MODKEY|ShiftMask,             XK_i,      spawn,          {.v = initscreen } },
	{ Mod1Mask,                     XK_p,      spawn,          {.v = dmenucmd } },
	{ Mod1Mask,                     XK_f,      spawn,          {.v = filecmd } },
	{ Mod1Mask,                     XK_w,      spawn,          {.v = webcmd } },
	{ Mod1Mask,                     XK_t,      spawn,          {.v = termcmd } },
    { MODKEY,                       XK_F10,    spawn,          {.v = mute}},
    { MODKEY,                       XK_F11,    spawn,          {.v = volumedown}},
    { MODKEY,                       XK_F12,    spawn,          {.v = volumeup}},
	{ MODKEY,                       XK_b,      togglebar,      {0} },
	{ Mod1Mask,                     XK_Tab,    focusstack,     {.i = +1 } },
/*	{ MODKEY,                       XK_k,      focusstack,     {.i = -1 } }, */
	{ MODKEY,                       XK_h,      incnmaster,     {.i = +1 } },
	{ MODKEY,                       XK_j,      incnmaster,     {.i = -1 } },
	{ MODKEY,                       XK_k,      setmfact,       {.f = -0.05} },
	{ MODKEY,                       XK_l,      setmfact,       {.f = +0.05} },
	{ MODKEY,                       XK_Return, zoom,           {0} },
	{ MODKEY,			            XK_q,      killclient,     {0} },
	{ MODKEY,                       XK_space,  setlayout,      {0} },
	{ MODKEY,                       XK_s,      togglefloating, {0} },
	{ MODKEY,                       XK_t,      setlayout,      {.v = &layouts[0]} },
	{ MODKEY,                       XK_f,      setlayout,      {.v = &layouts[1]} },
	{ MODKEY,                       XK_m,      setlayout,      {.v = &layouts[2]} },
	{ MODKEY,                       XK_0,      view,           {.ui = ~0 } },
	{ MODKEY|ShiftMask,             XK_0,      tag,            {.ui = ~0 } },
	{ MODKEY,                       XK_comma,  focusmon,       {.i = -1 } },
	{ MODKEY,                       XK_period, focusmon,       {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_comma,  tagmon,         {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_period, tagmon,         {.i = +1 } },
	TAGKEYS(                        XK_1,                      0)
	TAGKEYS(                        XK_2,                      1)
	TAGKEYS(                        XK_3,                      2)
	TAGKEYS(                        XK_4,                      3)
	TAGKEYS(                        XK_5,                      4)
	TAGKEYS(                        XK_6,                      5)
	TAGKEYS(                        XK_7,                      6)
	TAGKEYS(                        XK_8,                      7)
	TAGKEYS(                        XK_9,                      8)
	{ MODKEY|ShiftMask,             XK_q,      quit,           {0} },
};

/* button definitions */
/* click can be ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	{ ClkStatusText,        0,              Button2,        spawn,          {.v = termcmd } },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};
