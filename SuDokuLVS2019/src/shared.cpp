#include "shared.h"
#include "general.h"

void loadSettingsFile() {
	settingsFile = SDL_RWFromFile(SETTINGS_FILE, "rb");
	if (settingsFile == NULL) {
		initializeSettingsFileWithSettings(true, true, DEFAULT_RI, DEFAULT_ARI, DEFAULT_WIDTH, DEFAULT_HEIGHT, 1, 90, 50, 15, 22, DEFAULT_BG_SCALE);
	} else {
		SDL_RWread(settingsFile, &controlSettings, sizeof(ControlSettings), 1);
		SDL_RWread(settingsFile, &videoSettings, sizeof(VideoSettings), 1);
		SDL_RWread(settingsFile, &soundSettings, sizeof(SoundSettings), 1);
		SDL_RWread(settingsFile, &bgSettings, sizeof(BackgroundSettings), 1);
		SDL_RWclose(settingsFile);
	}
}

void initializeSettingsFileWithSettings(Sint8 scab, Sint8 et, Sint8 ri, Sint8 ari, Sint16 gw, Sint16 gh, Sint8 mi, Sint8 bgmv, Sint8 sfxv, Sint8 sm, Sint8 sd, Sint8 s) {
	settingsFile = SDL_RWFromFile(SETTINGS_FILE, "w+b");
	if (settingsFile != NULL) {
		controlSettings.swapConfirmAndBack = scab;
		controlSettings.enableTouchscreen = et;
		videoSettings.resolutionIndex = ri;
		videoSettings.aspectRatioIndex = ari;
		videoSettings.widthSetting = gw;
		videoSettings.heightSetting = gh;
		soundSettings.musicIndex = mi;
		soundSettings.bgmVolume = bgmv;
		soundSettings.sfxVolume = sfxv;
		bgSettings.speedMult = sm;
		bgSettings.scrollDir = sd;
		bgSettings.scale = s;
		SDL_RWwrite(settingsFile, &controlSettings.swapConfirmAndBack, sizeof(Uint8), 1);
		SDL_RWwrite(settingsFile, &controlSettings.enableTouchscreen, sizeof(Uint8), 1);
		SDL_RWwrite(settingsFile, &videoSettings.resolutionIndex, sizeof(Uint8), 1);
		SDL_RWwrite(settingsFile, &videoSettings.aspectRatioIndex, sizeof(Uint8), 1);
		SDL_RWwrite(settingsFile, &videoSettings.widthSetting, sizeof(Uint16), 1);
		SDL_RWwrite(settingsFile, &videoSettings.heightSetting, sizeof(Uint16), 1);
		SDL_RWwrite(settingsFile, &soundSettings.musicIndex, sizeof(Sint8), 1);
		SDL_RWwrite(settingsFile, &soundSettings.bgmVolume, sizeof(Sint8), 1);
		SDL_RWwrite(settingsFile, &soundSettings.sfxVolume, sizeof(Sint8), 1);
		SDL_RWwrite(settingsFile, &bgSettings.speedMult, sizeof(Sint8), 1);
		SDL_RWwrite(settingsFile, &bgSettings.scrollDir, sizeof(Sint8), 1);
		SDL_RWwrite(settingsFile, &bgSettings.scale, sizeof(Sint8), 1);
		SDL_RWclose(settingsFile);
	}
}

void initDefaultBGScale() {
	uint_i = (max(DEFAULT_WIDTH / 640, DEFAULT_HEIGHT / 480));
	defaultBGScale = max((Uint16)(uint_i), (Uint16)1);
}

void initStartingWidthHeightMults() {
	gameWidthMult = (gameWidth / 640.0);
	gameHeightMult = (gameHeight / 480.0);
}

void initStartingSharedVariables() {
	gridSizeA = (12 * GAME_HEIGHT_MULT);
	gridSizeB = (4 * GAME_HEIGHT_MULT);
	gridSizeC = (6 * GAME_HEIGHT_MULT);
	gridSizeD = (12 * GAME_HEIGHT_MULT);
	gridSize = (27 * GRID_SIZE_A + 6 * GRID_SIZE_B + 2 * GRID_SIZE_C + 2 * GRID_SIZE_D);
	gridSizeA3 = (3 * GRID_SIZE_A);
	gridPosX = (Uint16)((gameWidth / 2) - (GRID_SIZE / 2) + (GRID_SIZE * 5 / 24));
	gridPosY = (Uint16)((gameHeight - GRID_SIZE) / 2);
	sideBarSizeX = (Uint16)(GRID_SIZE / 3);
	sideBarSizeY = (Uint16)(GRID_SIZE / 4);
	sidebarSmallPosX = (Uint16)(GRID_POS_X - SIDEBAR_SIZE_X - (GRID_SIZE / 12));
	sidebarSmall1PosY = (Uint16)(GRID_POS_Y + (GRID_SIZE / 16));
	sidebarSmall2PosY = (Uint16)(GRID_POS_Y + SIDEBAR_SMALL_SIZE_Y + (GRID_SIZE / 8));
	sidebarSmall3PosY = (Uint16)(GRID_POS_Y + (2 * SIDEBAR_SMALL_SIZE_Y) + (GRID_SIZE * 3 / 16));
	gridStartingPosX[0] = (Uint16)((GRID_POS_X + GRID_SIZE_D) + (0 * GRID_SIZE_A3) + (0 * GRID_SIZE_B) + ((0 / 3) * (GRID_SIZE_C - GRID_SIZE_B)));
	gridStartingPosX[1] = (Uint16)((GRID_POS_X + GRID_SIZE_D) + (1 * GRID_SIZE_A3) + (1 * GRID_SIZE_B) + ((1 / 3) * (GRID_SIZE_C - GRID_SIZE_B)));
	gridStartingPosX[2] = (Uint16)((GRID_POS_X + GRID_SIZE_D) + (2 * GRID_SIZE_A3) + (2 * GRID_SIZE_B) + ((2 / 3) * (GRID_SIZE_C - GRID_SIZE_B)));
	gridStartingPosX[3] = (Uint16)((GRID_POS_X + GRID_SIZE_D) + (3 * GRID_SIZE_A3) + (3 * GRID_SIZE_B) + ((3 / 3) * (GRID_SIZE_C - GRID_SIZE_B)));
	gridStartingPosX[4] = (Uint16)((GRID_POS_X + GRID_SIZE_D) + (4 * GRID_SIZE_A3) + (4 * GRID_SIZE_B) + ((4 / 3) * (GRID_SIZE_C - GRID_SIZE_B)));
	gridStartingPosX[5] = (Uint16)((GRID_POS_X + GRID_SIZE_D) + (5 * GRID_SIZE_A3) + (5 * GRID_SIZE_B) + ((5 / 3) * (GRID_SIZE_C - GRID_SIZE_B)));
	gridStartingPosX[6] = (Uint16)((GRID_POS_X + GRID_SIZE_D) + (6 * GRID_SIZE_A3) + (6 * GRID_SIZE_B) + ((6 / 3) * (GRID_SIZE_C - GRID_SIZE_B)));
	gridStartingPosX[7] = (Uint16)((GRID_POS_X + GRID_SIZE_D) + (7 * GRID_SIZE_A3) + (7 * GRID_SIZE_B) + ((7 / 3) * (GRID_SIZE_C - GRID_SIZE_B)));
	gridStartingPosX[8] = (Uint16)((GRID_POS_X + GRID_SIZE_D) + (8 * GRID_SIZE_A3) + (8 * GRID_SIZE_B) + ((8 / 3) * (GRID_SIZE_C - GRID_SIZE_B)));
	gridStartingPosY[0] = (Uint16)((GRID_POS_Y + GRID_SIZE_D) + (0 * GRID_SIZE_A3) + (0 * GRID_SIZE_B) + ((0 / 3) * (GRID_SIZE_C - GRID_SIZE_B)));
	gridStartingPosY[1] = (Uint16)((GRID_POS_Y + GRID_SIZE_D) + (1 * GRID_SIZE_A3) + (1 * GRID_SIZE_B) + ((1 / 3) * (GRID_SIZE_C - GRID_SIZE_B)));
	gridStartingPosY[2] = (Uint16)((GRID_POS_Y + GRID_SIZE_D) + (2 * GRID_SIZE_A3) + (2 * GRID_SIZE_B) + ((2 / 3) * (GRID_SIZE_C - GRID_SIZE_B)));
	gridStartingPosY[3] = (Uint16)((GRID_POS_Y + GRID_SIZE_D) + (3 * GRID_SIZE_A3) + (3 * GRID_SIZE_B) + ((3 / 3) * (GRID_SIZE_C - GRID_SIZE_B)));
	gridStartingPosY[4] = (Uint16)((GRID_POS_Y + GRID_SIZE_D) + (4 * GRID_SIZE_A3) + (4 * GRID_SIZE_B) + ((4 / 3) * (GRID_SIZE_C - GRID_SIZE_B)));
	gridStartingPosY[5] = (Uint16)((GRID_POS_Y + GRID_SIZE_D) + (5 * GRID_SIZE_A3) + (5 * GRID_SIZE_B) + ((5 / 3) * (GRID_SIZE_C - GRID_SIZE_B)));
	gridStartingPosY[6] = (Uint16)((GRID_POS_Y + GRID_SIZE_D) + (6 * GRID_SIZE_A3) + (6 * GRID_SIZE_B) + ((6 / 3) * (GRID_SIZE_C - GRID_SIZE_B)));
	gridStartingPosY[7] = (Uint16)((GRID_POS_Y + GRID_SIZE_D) + (7 * GRID_SIZE_A3) + (7 * GRID_SIZE_B) + ((7 / 3) * (GRID_SIZE_C - GRID_SIZE_B)));
	gridStartingPosY[8] = (Uint16)((GRID_POS_Y + GRID_SIZE_D) + (8 * GRID_SIZE_A3) + (8 * GRID_SIZE_B) + ((8 / 3) * (GRID_SIZE_C - GRID_SIZE_B)));
	initNumOffsets();
}

void initNumOffsets() {
#if defined(VITA)
	d = (double)gameHeight / SCALING_HEIGHT;
	for (i = 0; i < 9; i++) {
		numOffset_large_x[i] = (Sint8)(2 * d);
		numOffset_large_y[i] = (Sint8)(d);
		numOffset_small_x[i] = 0;
		numOffset_small_y[i] = (Sint8)(-d);
	}
	numOffset_large_y[2] = 0;
	numOffset_large_y[5] = 0;
	numOffset_large_y[6] = 0;
	numOffset_large_y[7] = 0;
	numOffset_small_y[1] = 0;
	numOffset_small_y[3] = 0;
	if (gameHeight <= 240) {
		for (i = 0; i < 9; i++) numOffset_small_y[i] -= 1;
	}
#elif defined(PSP)
	d = (double)gameHeight / SCALING_HEIGHT;
	for (i = 0; i < 9; i++) {
		numOffset_large_x[i] = (Sint8)(d);
		numOffset_large_y[i] = 0;
		numOffset_small_x[i] = (Sint8)(d);
		numOffset_small_y[i] = (Sint8)(d);
	}
	numOffset_large_y[2] = (Sint8)(-d);
	numOffset_large_y[5] = (Sint8)(-d);
	numOffset_large_y[6] = (Sint8)(-d);
	numOffset_large_y[8] = (Sint8)(-d);
	numOffset_small_y[2] = 0;
	numOffset_small_y[5] = 0;
	numOffset_small_y[8] = 0;
#else
	for (i = 0; i < 9; i++) {
		numOffset_large_x[i] = 0;
		numOffset_large_y[i] = 0;
		numOffset_small_x[i] = 0;
		numOffset_small_y[i] = 0;
	}
#endif
}

void updateGlobalTimer() {
	timer_global.last = timer_global.now;
	timer_global.now = (SDL_GetTicks() - timer_paused.now) / 1000.0;
}

void preparePauseTimer() {
	timer_paused.last = SDL_GetTicks();
}

void updatePauseTimer() {
	timer_paused.now += (SDL_GetTicks() - timer_paused.last);
}

void initMenuOptionPositions(TextObject *textObj) {
	textObj->startPos_x = textObj->rect.x;
	textObj->startPos_y = textObj->rect.y;
	textObj->endPos_x = textObj->startPos_x + (gameWidth * 3 / 4);
	textObj->endPos_y = textObj->startPos_y - (gameWidth * 3 / 4);
}

void saveCurrentSettings() {
	initializeSettingsFileWithSettings(controlSettings.swapConfirmAndBack, controlSettings.enableTouchscreen,
		videoSettings.resolutionIndex, videoSettings.aspectRatioIndex, videoSettings.widthSetting, videoSettings.heightSetting,
		soundSettings.musicIndex, soundSettings.bgmVolume, soundSettings.sfxVolume,
		bgSettings.speedMult, bgSettings.scrollDir, bgSettings.scale);
}