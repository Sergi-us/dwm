/* See LICENSE file for copyright and license details. */
/* SARBS 27.10.2024 */
/* Constants */
#define TERMINAL "st"
#define TERMCLASS "St"
#define BROWSER "librewolf"

/* Erscheinungsbild */
static unsigned int borderpx	= 3;	/* Rahmenbreite der Fenster in Pixeln */
static unsigned int snap	= 32;	/* Einrastabstand in Pixeln */
static unsigned int gappih	= 20;	/* Horizontaler innerer Abstand zwischen Fenstern */
static unsigned int gappiv	= 10;	/* Vertikaler innerer Abstand zwischen Fenstern */
static unsigned int gappoh	= 10;	/* Horizontaler äußerer Abstand zwischen Fenstern und Bildschirmrand */
static unsigned int gappov	= 30;	/* Vertikaler äußerer Abstand zwischen Fenstern und Bildschirmrand */
static int swallowfloating	= 0;	/* 1 bedeutet schwebende Fenster standardmäßig "verschlucken" */
static int smartgaps		= 0;	/* 1 bedeutet kein äußerer Abstand wenn nur ein Fenster existiert */
static int showbar		= 1;	/* 0 bedeutet keine Statusleiste */
static int topbar		= 1;	/* 0 bedeutet Statusleiste unten statt oben */
static int user_bh		= 2;	/* 2 ist die Standart raum um die Schriftart */
static char *fonts[]		= { "JetBrainsMono NF ExtraLight:style=ExtraLight:size=12:antialias=true:autohint=true", "OpenMoji:size=10:antialias=true:autohint=true" };
static char normbgcolor[]           = "#222222";
static char normbordercolor[]       = "#444444";
static char normfgcolor[]           = "#bbbbbb";
static char selfgcolor[]            = "#eeeeee";
static char selbordercolor[]        = "#770000";
static char selbgcolor[]            = "#005577";
static char *colors[][3] = {
	/*               fg           bg           border   */
	[SchemeNorm] = { normfgcolor, normbgcolor, normbordercolor },
	[SchemeSel]  = { selfgcolor,  selbgcolor,  selbordercolor  },
};

typedef struct {
	const char *name;
	const void *cmd;
} Sp;
const char *spcmd1[] = {TERMINAL, "-n", "spterm", "-g", "120x33", NULL };
const char *spcmd2[] = {TERMINAL, "-n", "spcalc", "-f", "monospace:size=16", "-g", "50x20", "-e", "bc", "-lq", NULL };
static Sp scratchpads[] = {
	/* name          cmd  */
	{"spterm",      spcmd1},
	{"spcalc",      spcmd2},
};

/* tagging */
static const char *tags[] = { "1", "2", "3", "4", "5", "6", "7", "8", "9" };

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	*/
	/* class		instance    title			tags mask   isfloating	isterminal	noswallow  monitor */
	{ "Gimp",		NULL,		NULL,       	1 << 8,     0,			0,			0,        -1 },
	{ TERMCLASS,	NULL,       NULL,       	0,          0,			1,			0,        -1 },
	{ NULL,			NULL,       "Event Tester", 0,          0,			0,			1,        -1 },
	{ TERMCLASS,	"floatterm",NULL,       	0,			1,			1,			0,        -1 },
	{ TERMCLASS,	"bg",		NULL,       	1 << 7,     0,			1,			0,        -1 },
	{ TERMCLASS,	"spterm",   NULL,       	SPTAG(0),   1,			1,			0,        -1 },
	{ TERMCLASS,	"spcalc",   NULL,       	SPTAG(1),   1,			1,			0,        -1 },
};

/* layout(s) */
static float mfact     = 0.55;			/* Größenfaktor des Master-Bereichs [0.05..0.95] */
static int nmaster     = 1;				/* Anzahl der Clients im Master-Bereich */
static int resizehints = 0;				/* 1 bedeutet Größenhinweise bei gekachelter Anordnung beachten */
static const int lockfullscreen = 1;	/* 1 erzwingt den Fokus auf das Vollbild-Fenster */
#define FORCE_VSPLIT 1					/* nrowgrid Layout: erzwingt vertikale Teilung bei zwei Clients */
#include "vanitygaps.c"

/* Die verschiedenen Layouts */
static const Layout layouts[] = {
	/* Symbol   Anordnungsfunktion */
	{ "[]=",    tile },         /* Standard: Master links, Clients rechts */
	{ "TTT",    bstack },       /* Master oben, Clients unten */
	{ "[@]",    spiral },       /* Fibonacci-Spirale */
	{ "[\\]",   dwindle },      /* Nach rechts und links abnehmende Größe */
	{ "[D]",    deck },         /* Master links, Clients rechts im Monocle-Modus */
	{ "[M]",    monocle },      /* Alle Fenster übereinander */
	{ "|M|",    centeredmaster },    /* Master in der Mitte, Clients an den Seiten */
	{ ">M>",    centeredfloatingmaster }, /* Wie oben, aber Master schwebt */
	{ "><>",    NULL },         /* Keine Layout-Funktion bedeutet schwebendes Verhalten */
	{ NULL,     NULL },
};

/* key definitions */
#define MODKEY Mod4Mask			/* setzt Windows Taste als Haupt-Modifyer */
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },
#define STACKKEYS(MOD,ACTION) \
	{ MOD,		XK_j,		ACTION##stack,	{.i = INC(+1) } }, \
	{ MOD,		XK_k,		ACTION##stack,	{.i = INC(-1) } }, \
	/* { MOD,	XK_v,		ACTION##stack,  {.i = 0 } }, \ */
	/* { MOD,	XK_grave,	ACTION##stack,	{.i = PREVSEL } }, \ */
	/* { MOD,	XK_a,		ACTION##stack,	{.i = 1 } }, \ */
	/* { MOD,	XK_z,		ACTION##stack,	{.i = 2 } }, \ */
	/* { MOD,	XK_x,		ACTION##stack,	{.i = -1 } }, */

/* definiert ein Makro "SHCMD" das Shell-Befehle in DWM ausführt. */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static const char *termcmd[]  = { TERMINAL, NULL };

/*
 * Xresources preferences to load at startup
 */
ResourcePref resources[] = {
		{ "color0",			STRING,		&normbordercolor },
		{ "color8",			STRING,		&selbordercolor },
		{ "color0",			STRING,		&normbgcolor },
		{ "color4",			STRING,		&normfgcolor },
		{ "color0",			STRING,		&selfgcolor },
		{ "color4",			STRING,		&selbgcolor },
		{ "borderpx",		INTEGER,	&borderpx },
		{ "snap",			INTEGER,	&snap },
		{ "showbar",		INTEGER,	&showbar },
		{ "topbar",			INTEGER,	&topbar },
		{ "nmaster",		INTEGER,	&nmaster },
		{ "resizehints",	INTEGER,	&resizehints },
		{ "mfact",			FLOAT,		&mfact },
		{ "gappih",			INTEGER,	&gappih },
		{ "gappiv",			INTEGER,	&gappiv },
		{ "gappoh",			INTEGER,	&gappoh },
		{ "gappov",			INTEGER,	&gappov },
		{ "swallowfloating",INTEGER,	&swallowfloating },
		{ "smartgaps",		INTEGER,	&smartgaps },
};

#include <X11/XF86keysym.h>
#include "shiftview.c"

static const Key keys[] = {
	/* modifier		key					function        argument */
	STACKKEYS(MODKEY,					focus)
	STACKKEYS(MODKEY|ShiftMask,			push)
	/* { MODKEY|ShiftMask,	XK_Escape,	spawn,	SHCMD("") },	*/
	{ MODKEY,		XK_dead_circumflex,	spawn,			{.v = (const char*[]){ "dmenuunicode", NULL } } },
	/* { MODKEY|ShiftMask,	XK_grave,			togglescratch,	SHCMD("") }, */
	TAGKEYS(		XK_1,				0)
	TAGKEYS(		XK_2,				1)
	TAGKEYS(		XK_3,				2)
	TAGKEYS(		XK_4,				3)
	TAGKEYS(		XK_5,				4)
	TAGKEYS(		XK_6,				5)
	TAGKEYS(		XK_7,				6)
	TAGKEYS(		XK_8,				7)
	TAGKEYS(		XK_9,				8)
	{ MODKEY,		XK_0,				view,			{.ui = ~0 } },
	{ MODKEY|ShiftMask,	XK_0,			tag,			{.ui = ~0 } },
	{ MODKEY,		XK_minus,			spawn,			SHCMD("wpctl set-volume @DEFAULT_AUDIO_SINK@ 5%-; kill -44 $(pidof dwmblocks)") },
	{ MODKEY|ShiftMask,	XK_minus,		spawn,			SHCMD("wpctl set-volume @DEFAULT_AUDIO_SINK@ 15%-; kill -44 $(pidof dwmblocks)") },
	{ MODKEY,		XK_equal,			spawn,			SHCMD("wpctl set-volume @DEFAULT_AUDIO_SINK@ 5%+; kill -44 $(pidof dwmblocks)") },
	{ MODKEY|ShiftMask,	XK_equal,		spawn,			SHCMD("wpctl set-volume @DEFAULT_AUDIO_SINK@ 15%+; kill -44 $(pidof dwmblocks)") },
	{ MODKEY,		XK_BackSpace,		spawn,			{.v = (const char*[]){ "sysact", NULL } } },
	{ MODKEY|ShiftMask,	XK_BackSpace,	spawn,			{.v = (const char*[]){ "sysact", NULL } } },

    { MODKEY,		XK_v,				spawn,			SHCMD("vncviewer localhost:5901") },
	{ MODKEY,		XK_Tab,				view,			{0} },
	/*{ MODKEY|ShiftMask,	XK_Tab,				spawn,			SHCMD("") },*/
	{ MODKEY,		XK_q,				killclient,		{0} },
	{ MODKEY|ShiftMask,	XK_q,				spawn,			{.v = (const char*[]){ "sysact", NULL } } },
	{ MODKEY,		XK_w,				spawn,			{.v = (const char*[]){ BROWSER, NULL } } },
	{ MODKEY|ShiftMask,	XK_w,				spawn,			{.v = (const char*[]){ TERMINAL, "-e", "sudo", "nmtui", NULL } } },
	{ MODKEY,		XK_e,				spawn,			SHCMD(TERMINAL " -e neomutt ; pkill -RTMIN+12 dwmblocks") },
	{ MODKEY|ShiftMask,	XK_e,				spawn,			SHCMD(TERMINAL " -e abook -C ~/.config/abook/abookrc --datafile ~/.abook/addressbook") },
	{ MODKEY,		XK_r,				spawn,			{.v = (const char*[]){ TERMINAL, "-e", "lfub", NULL } } },
	{ MODKEY|ShiftMask,	XK_r,				spawn,			{.v = (const char*[]){ TERMINAL, "-e", "btop", NULL } } },
	{ MODKEY,		XK_t,				setlayout,		{.v = &layouts[0]} }, /* tile */
	{ MODKEY|ShiftMask,	XK_t,				setlayout,		{.v = &layouts[1]} }, /* bstack */
	{ MODKEY,		XK_z,				setlayout,		{.v = &layouts[2]} }, /* spiral */
	{ MODKEY|ShiftMask,	XK_z,				setlayout,		{.v = &layouts[3]} }, /* dwindle */
	{ MODKEY,		XK_u,				setlayout,		{.v = &layouts[4]} }, /* deck */
	{ MODKEY|ShiftMask,	XK_u,				setlayout,		{.v = &layouts[5]} }, /* monocle */
	{ MODKEY,		XK_i,				setlayout,		{.v = &layouts[6]} }, /* centeredmaster */
	{ MODKEY|ShiftMask,	XK_i,				setlayout,		{.v = &layouts[7]} }, /* centeredfloatingmaster */
	{ MODKEY,		XK_o,				incnmaster,		{.i = +1 } },
	{ MODKEY|ShiftMask,	XK_o,				incnmaster,		{.i = -1 } },
	{ MODKEY,		XK_p,				spawn,			{.v = (const char*[]){ "mpc", "toggle", NULL } } },
	{ MODKEY|ShiftMask,	XK_p,				spawn,			SHCMD("mpc pause; pauseallmpv") },
	{ MODKEY,		XK_bracketleft,		spawn,			{.v = (const char*[]){ "mpc", "seek", "-10", NULL } } },
	{ MODKEY|ShiftMask,	XK_bracketleft,		spawn,			{.v = (const char*[]){ "mpc", "seek", "-60", NULL } } },
	{ MODKEY,		XK_bracketright,	spawn,			{.v = (const char*[]){ "mpc", "seek", "+10", NULL } } },
	{ MODKEY|ShiftMask,	XK_bracketright,	spawn,			{.v = (const char*[]){ "mpc", "seek", "+60", NULL } } },
	{ MODKEY,		XK_backslash,		view,			{0} },
	/* { MODKEY|ShiftMask,	XK_backslash,		spawn,			SHCMD("") }, */
	{ MODKEY,		XK_a,				togglegaps,		{0} },
	{ MODKEY|ShiftMask,	XK_a,				defaultgaps,	{0} },
	{ MODKEY,		XK_s,				togglesticky,	{0} },
	/* { MODKEY|ShiftMask,	XK_s,				spawn,			SHCMD("") }, */
	{ MODKEY,		XK_d,				spawn,			{.v = (const char*[]){ "dmenu_run", NULL } } },
	{ MODKEY|ShiftMask,	XK_d,				spawn,			{.v = (const char*[]){ "passmenu", NULL } } },
	{ MODKEY,		XK_f,				togglefullscr,	{0} },
	{ MODKEY|ShiftMask,	XK_f,				setlayout,		{.v = &layouts[8]} },
	{ MODKEY,		XK_g,				shiftview,		{ .i = -1 } },
	{ MODKEY|ShiftMask,	XK_g,				shifttag,		{ .i = -1 } },
	{ MODKEY,		XK_h,				setmfact,		{.f = -0.05} },
	/* J and K are automatically bound above in STACKEYS */
	{ MODKEY,		XK_l,				setmfact,		{.f = +0.05} },
	{ MODKEY,		XK_semicolon,		shiftview,		{ .i = 1 } },
	{ MODKEY|ShiftMask,	XK_semicolon,		shifttag,		{ .i = 1 } },
	{ MODKEY,		XK_apostrophe,		togglescratch,	{.ui = 1} },
	/*{ MODKEY|ShiftMask,	XK_apostrophe,		spawn,			SHCMD("") }, */
	{ MODKEY|ShiftMask,	XK_apostrophe,		togglesmartgaps,	{0} },
	{ MODKEY,		XK_Return,			spawn,			{.v = termcmd } },
	{ MODKEY|ShiftMask,	XK_Return,			togglescratch,	{.ui = 0} },
	{ MODKEY,		XK_y,				incrgaps,		{.i = +3 } },
	/* { MODKEY|ShiftMask,	XK_y,				spawn,			SHCMD("") }, */
	{ MODKEY,		XK_x,				incrgaps,		{.i = -3 } },
	/* { MODKEY|ShiftMask,	XK_x,				spawn,			SHCMD("") }, */
	{ MODKEY,		XK_c,				spawn,			{.v = (const char*[]){ TERMINAL, "-e", "profanity", NULL } } },
	/* { MODKEY|ShiftMask,	XK_c,				spawn,			SHCMD("") }, */
	/* V is automatically bound above in STACKKEYS */
	{ MODKEY,		XK_b,				togglebar,		{0} },
	/* { MODKEY|ShiftMask,	XK_b,				spawn,			{.v = (const char*[]){ "bookmarkthis", NULL} } }, */
	{ MODKEY,		XK_n,				spawn,			{.v = (const char*[]){ TERMINAL, "-e", "nvim", "-c", "VimwikiIndex", NULL } } },
	{ MODKEY|ShiftMask,	XK_n,			spawn,			SHCMD(TERMINAL " -e newsboat ; pkill -RTMIN+6 dwmblocks") },
	{ MODKEY,		XK_m,			spawn,			{.v = (const char*[]){ TERMINAL, "-e", "ncmpcpp", NULL } } },
	/* { MODKEY|ShiftMask,	XK_m,			spawn,			SHCMD("wpctl set-mute @DEFAULT_AUDIO_SINK@ toggle; kill -44 $(pidof dwmblocks)") }, */
	{ MODKEY,		XK_comma,		spawn,			{.v = (const char*[]){ "mpc", "prev", NULL } } },
	{ MODKEY|ShiftMask,	XK_comma,		spawn,			{.v = (const char*[]){ "mpc", "seek", "0%", NULL } } },
	{ MODKEY,		XK_period,		spawn,			{.v = (const char*[]){ "mpc", "next", NULL } } },
	{ MODKEY|ShiftMask,	XK_period,		spawn,			{.v = (const char*[]){ "mpc", "repeat", NULL } } },
	{ MODKEY,		XK_Left,		focusmon,		{.i = -1 } },
	{ MODKEY|ShiftMask,	XK_Left,		tagmon,			{.i = -1 } },
	{ MODKEY,		XK_Right,		focusmon,		{.i = +1 } },
	{ MODKEY|ShiftMask,	XK_Right,		tagmon,			{.i = +1 } },
	{ MODKEY,		XK_Page_Up,		shiftview,		{ .i = -1 } },
	{ MODKEY|ShiftMask,	XK_Page_Up,		shifttag,		{ .i = -1 } },
	{ MODKEY,		XK_Page_Down,		shiftview,		{ .i = +1 } },
	{ MODKEY|ShiftMask,	XK_Page_Down,		shifttag,		{ .i = +1 } },
	{ MODKEY,		XK_Insert,		spawn,		SHCMD("xdotool type $(grep -v '^#' ~/.local/share/sarbs/snippets | dmenu -i -l 30 | cut -d' ' -f1)") },
	{ MODKEY|ShiftMask,	XK_Insert,		spawn,			{.v = (const char*[]){ "bookmarkthis", NULL} } },
	{ MODKEY,		XK_F1,			spawn,			SHCMD("preconv -e utf8 /usr/local/share/dwm/sarbs.mom | groff -mom -Tpdf | zathura -") },
	{ MODKEY|ShiftMask,	XK_F1,			togglescratch,		{.ui = 2} },
	{ MODKEY,		XK_F2,			spawn,			{.v = (const char*[]){ "tutorialvids", NULL } } },
	{ MODKEY,		XK_F3,			spawn,			{.v = (const char*[]){ "displayselect", NULL } } },
	{ MODKEY,		XK_F4,			spawn,			SHCMD(TERMINAL " -e pulsemixer; kill -44 $(pidof dwmblocks)") },
	{ MODKEY,		XK_F5,			xrdb,			{.v = NULL } },
	{ MODKEY,		XK_F6,			spawn,			{.v = (const char*[]){ "torwrap", NULL } } },
	{ MODKEY,		XK_F7,			spawn,			{.v = (const char*[]){ "td-toggle", NULL } } },
	{ MODKEY,		XK_F8,			spawn,			{.v = (const char*[]){ "mailsync", NULL } } },
	{ MODKEY,		XK_F9,			spawn,			{.v = (const char*[]){ "mounter", NULL } } },
	{ MODKEY,		XK_F10,			spawn,			{.v = (const char*[]){ "unmounter", NULL } } },
	{ MODKEY|ShiftMask,	XK_F10,     spawn,          SHCMD("scrcpy --no-audio --keyboard=sdk --disable-screensaver --window-borderless --mouse=sdk --new-display=2000x2000") },
	{ MODKEY,		XK_F11,			spawn,			{.v = (const char*[]){ "cam", NULL } } },
	{ MODKEY|ShiftMask,	XK_F11,     spawn,          SHCMD("scrcpy --no-audio --keyboard=sdk --disable-screensaver --window-borderless") },
	{ MODKEY,		XK_F12,			spawn,			SHCMD("remaps") },
	{ MODKEY,		XK_space,		zoom,			{0} },
	{ MODKEY|ShiftMask,	XK_space,		togglefloating,	{0} },

	{ 0,			XK_Print,		spawn,			SHCMD("maim ~/Bilder/screenshots/pic-vollbild-$(date '+%y%m%d-%H%M-%S').png") },
	{ ShiftMask,		XK_Print,		spawn,			{.v = (const char*[]){ "maimpick", NULL } } },
	{ MODKEY,		XK_Print,		spawn,			{.v = (const char*[]){ "dmenurecord", NULL } } },
	{ MODKEY|ShiftMask,	XK_Print,		togglescratch,	{.ui = 1 } },
	/*{ MODKEY|ShiftMask,	XK_Print,		spawn,			{.v = (const char*[]){ "dmenurecord", "kill", NULL } } },*/
	{ MODKEY,		XK_Delete,		spawn,			{.v = (const char*[]){ "dmenurecord", "kill", NULL } } },
	{ MODKEY,		XK_Home,		spawn,			SHCMD("killall screenkey || screenkey &") },

	{ 0,	XF86XK_AudioMute,					spawn,			SHCMD("wpctl set-mute @DEFAULT_AUDIO_SINK@ toggle; kill -44 $(pidof dwmblocks)") },
	{ 0,	XF86XK_AudioRaiseVolume,			spawn,			SHCMD("wpctl set-volume @DEFAULT_AUDIO_SINK@ 0%- && wpctl set-volume @DEFAULT_AUDIO_SINK@ 3%+; kill -44 $(pidof dwmblocks)") },
	{ 0,	XF86XK_AudioLowerVolume,			spawn,			SHCMD("wpctl set-volume @DEFAULT_AUDIO_SINK@ 0%+ && wpctl set-volume @DEFAULT_AUDIO_SINK@ 3%-; kill -44 $(pidof dwmblocks)") },
	{ 0,	XF86XK_AudioPrev,					spawn,			{.v = (const char*[]){ "mpc", "prev", NULL } } },
	{ 0,	XF86XK_AudioNext,					spawn,			{.v = (const char*[]){ "mpc", "next", NULL } } },
	{ 0,	XF86XK_AudioPause,					spawn,			{.v = (const char*[]){ "mpc", "pause", NULL } } },
	{ 0,	XF86XK_AudioPlay,					spawn,			{.v = (const char*[]){ "mpc", "play", NULL } } },
	{ 0,	XF86XK_AudioStop,					spawn,			{.v = (const char*[]){ "mpc", "stop", NULL } } },
	{ 0,	XF86XK_AudioRewind,					spawn,			{.v = (const char*[]){ "mpc", "seek", "-10", NULL } } },
	{ 0,	XF86XK_AudioForward,				spawn,			{.v = (const char*[]){ "mpc", "seek", "+10", NULL } } },
	{ 0,	XF86XK_AudioMedia,					spawn,			{.v = (const char*[]){ TERMINAL, "-e", "ncmpcpp", NULL } } },
	{ 0,	XF86XK_AudioMicMute,				spawn,			SHCMD("pactl set-source-mute @DEFAULT_SOURCE@ toggle") },
	{ 0,	XF86XK_PowerOff,					spawn,			{.v = (const char*[]){ "shutdown", "-h", "now", NULL } } },
	{ 0,	XF86XK_Calculator,					spawn,			{.v = (const char*[]){ TERMINAL, "-e", "bc", "-l", NULL } } },
	{ 0,	XF86XK_Sleep,						spawn,			{.v = (const char*[]){ "sudo", "-A", "zzz", NULL } } },
	{ 0,	XF86XK_WWW,							spawn,			{.v = (const char*[]){ BROWSER, NULL } } },
	{ 0,	XF86XK_DOS,							spawn,			{.v = termcmd } },
	{ 0,	XF86XK_ScreenSaver,					spawn,			SHCMD("slock & xset dpms force off; mpc pause; pauseallmpv") },
	{ 0,	XF86XK_TaskPane,					spawn,			{.v = (const char*[]){ TERMINAL, "-e", "btop", NULL } } },
	{ 0,	XF86XK_Mail,						spawn,			SHCMD(TERMINAL " -e neomutt ; pkill -RTMIN+12 dwmblocks") },
	{ 0,	XF86XK_MyComputer,					spawn,			{.v = (const char*[]){ TERMINAL, "-e",  "lfub",  "/", NULL } } },
	/* { 0,		XF86XK_Battery,						spawn,			SHCMD("") }, */
	{ 0,	XF86XK_Launch1,						spawn,			{.v = (const char*[]){ "xset", "dpms", "force", "off", NULL } } },
	{ 0,	XF86XK_TouchpadToggle,				spawn,			SHCMD("(synclient | grep 'TouchpadOff.*1' && synclient TouchpadOff=0) || synclient TouchpadOff=1") },
	{ 0,	XF86XK_TouchpadOff,					spawn,			{.v = (const char*[]){ "synclient", "TouchpadOff=1", NULL } } },
	{ 0,	XF86XK_TouchpadOn,					spawn,			{.v = (const char*[]){ "synclient", "TouchpadOff=0", NULL } } },
	{ 0,	XF86XK_MonBrightnessUp,				spawn,			{.v = (const char*[]){ "xbacklight", "-inc", "15", NULL } } },
	{ 0,	XF86XK_MonBrightnessDown,			spawn,			{.v = (const char*[]){ "xbacklight", "-dec", "15", NULL } } },

	/* { MODKEY|Mod4Mask,              XK_h,      incrgaps,       {.i = +1 } }, */
	/* { MODKEY|Mod4Mask,              XK_l,      incrgaps,       {.i = -1 } }, */
	/* { MODKEY|Mod4Mask|ShiftMask,    XK_h,      incrogaps,      {.i = +1 } }, */
	/* { MODKEY|Mod4Mask|ShiftMask,    XK_l,      incrogaps,      {.i = -1 } }, */
	/* { MODKEY|Mod4Mask|ControlMask,  XK_h,      incrigaps,      {.i = +1 } }, */
	/* { MODKEY|Mod4Mask|ControlMask,  XK_l,      incrigaps,      {.i = -1 } }, */
	/* { MODKEY|Mod4Mask|ShiftMask,    XK_0,      defaultgaps,    {0} }, */
	/* { MODKEY,                       XK_y,      incrihgaps,     {.i = +1 } }, */
	/* { MODKEY,                       XK_o,      incrihgaps,     {.i = -1 } }, */
	/* { MODKEY|ControlMask,           XK_y,      incrivgaps,     {.i = +1 } }, */
	/* { MODKEY|ControlMask,           XK_o,      incrivgaps,     {.i = -1 } }, */
	/* { MODKEY|Mod4Mask,              XK_y,      incrohgaps,     {.i = +1 } }, */
	/* { MODKEY|Mod4Mask,              XK_o,      incrohgaps,     {.i = -1 } }, */
	/* { MODKEY|ShiftMask,             XK_y,      incrovgaps,     {.i = +1 } }, */
	/* { MODKEY|ShiftMask,             XK_o,      incrovgaps,     {.i = -1 } }, */

};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static const Button buttons[] = {
	/* click                event mask      button          function        argument */
#ifndef __OpenBSD__
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	{ ClkStatusText,        0,              Button1,        sigdwmblocks,   {.i = 1} },
	{ ClkStatusText,        0,              Button2,        sigdwmblocks,   {.i = 2} },
	{ ClkStatusText,        0,              Button3,        sigdwmblocks,   {.i = 3} },
	{ ClkStatusText,        0,              Button4,        sigdwmblocks,   {.i = 4} },
	{ ClkStatusText,        0,              Button5,        sigdwmblocks,   {.i = 5} },
	{ ClkStatusText,        ShiftMask,      Button1,        sigdwmblocks,   {.i = 6} },
#endif
	{ ClkStatusText,        ShiftMask,      Button3,        spawn,          SHCMD(TERMINAL " -e nvim ~/.local/src/dwmblocks/config.h") },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        defaultgaps,	{0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkClientWin,		MODKEY,		Button4,	incrgaps,	{.i = +1} },
	{ ClkClientWin,		MODKEY,		Button5,	incrgaps,	{.i = -1} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
	{ ClkTagBar,		0,		Button4,	shiftview,	{.i = -1} },
	{ ClkTagBar,		0,		Button5,	shiftview,	{.i = 1} },
	{ ClkRootWin,		0,		Button2,	togglebar,	{0} },
};

