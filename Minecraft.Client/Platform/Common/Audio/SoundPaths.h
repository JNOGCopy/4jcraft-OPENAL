#include <string>
#include <vector>

const std::vector<std::vector<std::string>> paths =
{
	{ "mob/chicken/say1", "mob/chicken/say2", "mob/chicken/say3" },						//	eSoundType_MOB_CHICKEN_AMBIENT	
	{ "mob/chicken/hurt1", "mob/chicken/hurt2" },					//	eSoundType_MOB_CHICKEN_HURT
	{ "mob/chicken/plop" },					//	eSoundType_MOB_CHICKENPOP
	{ "mob/cow/say1", "mob/cow/say2", "mob/cow/say3", "mob/cow/say4" },							//	eSoundType_MOB_COW_AMBIENT
	{ "mob/cow/hurt1", "mob/cow/hurt2", "mob/cow/hurt3", },						//	eSoundType_MOB_COW_HURT
	{ "mob/pig1", "mob/pig2", "mob/pig3" },							//	eSoundType_MOB_PIG_AMBIENT
	{ "mob/pigdeath" },					//	eSoundType_MOB_PIG_DEATH
	{ "mob/sheep1", "mob/sheep2", "mob/sheep3" },						//	eSoundType_MOB_SHEEP_AMBIENT
	{ "mob/wolf/growl1", "mob/wolf/growl2", "mob/wolf/growl3" },					//	eSoundType_MOB_WOF_GROW
	{ "mob/wolf/whine" },					//	eSoundType_MOB_WOF_WHINE
	{ "mob/wolf/panting" },				//	eSoundType_MOB_WOF_PANTING
	{ "mob/wolf/bark1", "mob/wolf/bark2", "mob/wolf/bark3" },					//	eSoundType_MOB_WOF_BARK
	{ "mob/wolf/hurt1", "mob/wolf/hurt2", "mob/wolf/hurt3"  },					//	eSoundType_MOB_WOF_HURT
	{ "mob/wolf/death" },					//	eSoundType_MOB_WOF_DEATH
	{ "mob/wolf/shake" },					//	eSoundType_MOB_WOF_SHAKE
	{ "mob/blaze/breathe1", "mob/blaze/breathe2", "mob/blaze/breathe3", "mob/blaze/breathe4" },				//	eSoundType_MOB_BAZE_BREATHE
	{ "mob/blaze/hit1", "mob/blaze/hit2", "mob/blaze/hit3" },					//	eSoundType_MOB_BAZE_HURT
	{ "mob/blaze/death" },					//	eSoundType_MOB_BAZE_DEATH
	{ "mob/ghast/moan1", "mob/ghast/moan2", "mob/ghast/moan3", "mob/ghast/moan4", "mob/ghast/moan5", "mob/ghast/moan6", "mob/ghast/moan7" },					//	eSoundType_MOB_GHAST_MOAN
	{ "mob/ghast/scream1", "mob/ghast/scream2", "mob/ghast/scream3", "mob/ghast/scream4", "mob/ghast/scream5" },				//	eSoundType_MOB_GHAST_SCREAM
	{ "mob/ghast/death" },					//	eSoundType_MOB_GHAST_DEATH
	{ "mob/ghast/fireball4" },				//	eSoundType_MOB_GHAST_FIREBA
	{ "mob/ghast/charge" },				//	eSoundType_MOB_GHAST_CHARGE
	{ "mob/endermen/idle1", "mob/endermen/idle2", "mob/endermen/idle3", "mob/endermen/idle4", "mob/endermen/idle5" },				//	eSoundType_MOB_ENDERMEN_IDE
	{ "mob/endermen/hit1", "mob/endermen/hit2", "mob/endermen/hit3", "mob/endermen/hit4" },				//	eSoundType_MOB_ENDERMEN_HIT
	{ "mob/endermen/death" },				//	eSoundType_MOB_ENDERMEN_DEATH
	{ "mob/endermen/portal", "mob/endermen/portal2" },				//	eSoundType_MOB_ENDERMEN_PORTA
	{ "mob/zombiepig/zpig1", "mob/zombiepig/zpig2", "mob/zombiepig/zpig3", "mob/zombiepig/zpig4" },				//	eSoundType_MOB_ZOMBIEPIG_AMBIENT
	{ "mob/zombiepig/zpighurt1", "mob/zombiepig/zpighurt2" },			//	eSoundType_MOB_ZOMBIEPIG_HURT
	{ "mob/zombiepig/zpigdeath" },			//	eSoundType_MOB_ZOMBIEPIG_DEATH
	{ "mob/zombiepig/zpigangry1", "mob/zombiepig/zpigangry2", "mob/zombiepig/zpigangry3", "mob/zombiepig/zpigangry4" },			//	eSoundType_MOB_ZOMBIEPIG_ZPIGANGRY
	{ "mob/silverfish/say1", "mob/silverfish/say2", "mob/silverfish/say3", "mob/silverfish/say4" },				//	eSoundType_MOB_SIVERFISH_AMBIENT,
	{ "mob/silverfish/hit1", "mob/silverfish/hit2", "mob/silverfish/hit3" },				//	eSoundType_MOB_SIVERFISH_HURT
	{ "mob/silverfish/kill" },				//	eSoundType_MOB_SIVERFISH_DEATH,
	{ "mob/silverfish/step1", "mob/silverfish/step2", "mob/silverfish/step3" },				//	eSoundType_MOB_SIVERFISH_STEP,
	{ "mob/skeleton1", "mob/skeleton2", "mob/skeleton3" },					//	eSoundType_MOB_SKEETON_AMBIENT,
	{ "mob/skeletonhurt1", "mob/skeletonhurt2", "mob/skeletonhurt3", "mob/skeletonhurt4" },				//	eSoundType_MOB_SKEETON_HURT,
	{ "mob/spider1", "mob/spider2", "mob/spider3", "mob/spider4" },						//	eSoundType_MOB_SPIDER_AMBIENT,
	{ "mob/spiderdeath" },					//	eSoundType_MOB_SPIDER_DEATH,
	{ "mob/slime1", "mob/slime2", "mob/slime3", "mob/slime4", "mob/slime5" },						//	eSoundType_MOB_SIME,
	{ "mob/slimeattack1", "mob/slimeattack2" },					//	eSoundType_MOB_SIME_ATTACK,
	{ "mob/creeper1", "mob/creeper2", "mob/creeper3", "mob/creeper4" },						//	eSoundType_MOB_CREEPER_HURT,
	{ "mob/creeperdeath" },				//	eSoundType_MOB_CREEPER_DEATH,
	{ "mob/zombie1", "mob/zombie2", "mob/zombie3" },						//	eSoundType_MOB_ZOMBIE_AMBIENT,
	{ "mob/zombiehurt1", "mob/zombiehurt2" },					//	eSoundType_MOB_ZOMBIE_HURT,
	{ "mob/zombiedeath" },					//	eSoundType_MOB_ZOMBIE_DEATH,
	{ "mob/zombie/wood1", "mob/zombie/wood2", "mob/zombie/wood3", "mob/zombie/wood4" },					//	eSoundType_MOB_ZOMBIE_WOOD,
	{ "mob/zombie/woodbreak" },			//	eSoundType_MOB_ZOMBIE_WOOD_BREAK,
	{ "mob/zombie/metal1", "mob/zombie/metal2", "mob/zombie/metal3" },				//	eSoundType_MOB_ZOMBIE_META,
	{ "mob/magmacube/big1", "mob/magmacube/big2", "mob/magmacube/big3", "mob/magmacube/big4" },				//	eSoundType_MOB_MAGMACUBE_BIG,
	{ "mob/magmacube/small1", "mob/magmacube/small2", "mob/magmacube/small3", "mob/magmacube/small4", "mob/magmacube/small5" },				//	eSoundType_MOB_MAGMACUBE_SMA,
	{ "mob/cat/purr1", "mob/cat/purr2", "mob/cat/purr3" },					//  eSoundType_MOB_CAT_PURR
	{ "mob/cat/purreow1", "mob/cat/purreow2" },					//  eSoundType_MOB_CAT_PURREOW
	{ "mob/cat/meow1", "mob/cat/meow2", "mob/cat/meow3", "mob/cat/meow4" },					//  eSoundType_MOB_CAT_MEOW
	// 4J-PB - correct the name of the event for hitting ocelots
	{ "mob/cat/hit1", "mob/cat/hit2", "mob/cat/hit3" },					//  eSoundType_MOB_CAT_HITT
//	"mob/irongolem/throw",				//  eSoundType_MOB_IRONGOEM_THROW
//	"mob/irongolem/hit",				//  eSoundType_MOB_IRONGOEM_HIT
//	"mob/irongolem/death",				//  eSoundType_MOB_IRONGOEM_DEATH
//	"mob/irongolem/walk",				//  eSoundType_MOB_IRONGOEM_WAK
	{ "random/bow" },						//	eSoundType_RANDOM_BOW,
	{ "random/bowhit1", "random/bowhit2", "random/bowhit3", "random/bowhit4" },					//	eSoundType_RANDOM_BOW_HIT,
	{ "random/explode1", "random/explode2", "random/explode3", "random/explode4", "random/explode" },					//	eSoundType_RANDOM_EXPODE,
	{ "random/fizz" },						//	eSoundType_RANDOM_FIZZ,	
	{ "random/pop" },						//	eSoundType_RANDOM_POP,
	{ "random/fuse" },						//	eSoundType_RANDOM_FUSE,
	{ "random/drink" },					//	eSoundType_RANDOM_DRINK,
	{ "random/eat1", "random/eat2", "random/eat3" },						//	eSoundType_RANDOM_EAT,
	{ "random/burp" },						//	eSoundType_RANDOM_BURP,
	{ "random/splash" },					//	eSoundType_RANDOM_SPASH,
	{ "random/click" },					//	eSoundType_RANDOM_CICK,
	{ "random/glass1", "random/glass2", "random/glass3" },					//	eSoundType_RANDOM_GASS,
	{ "random/orb" },						//	eSoundType_RANDOM_ORB,
	{ "random/break" },					//	eSoundType_RANDOM_BREAK,
	{ "random/chestopen" },				//	eSoundType_RANDOM_CHEST_OPEN,
	{ "random/chestclosed" },				//	eSoundType_RANDOM_CHEST_COSE,
	{ "random/door_open" },				//	eSoundType_RANDOM_DOOR_OPEN,
	{ "random/door_close" },				//	eSoundType_RANDOM_DOOR_COSE,
	{ "ambient/weather/rain1", "ambient/weather/rain2", "ambient/weather/rain3", "ambient/weather/rain4" },			//	eSoundType_AMBIENT_WEATHER_RAIN,
	{ "ambient/weather/thunder1", "ambient/weather/thunder2", "ambient/weather/thunder3" },			//	eSoundType_AMBIENT_WEATHER_THUNDER,
	{ "ambient/cave/cave1", "ambient/cave/cave2", "ambient/cave/cave3", "ambient/cave/cave4", "ambient/cave/cave5", "ambient/cave/cave6", "ambient/cave/cave7", "ambient/cave/cave8", "ambient/cave/cave9", "ambient/cave/cave10", "ambient/cave/cave11", "ambient/cave/cave12", "ambient/cave/cave13" },				//	eSoundType_CAVE_CAVE, DON'T USE FOR XBOX 360!!!
#ifdef _XBOX
	"ambient/cave/cave2",				//	eSoundType_CAVE_CAVE2 - removed the two sounds that were at 192k in the first ambient cave event
#endif
	{ "portal/portal" },					//	eSoundType_PORTA_PORTA,
	// 4J-PB - added a couple that were still using std::wstring
	{ "portal/trigger" },					//	eSoundType_PORTA_TRIGGER
	{ "portal/travel" },					//	eSoundType_PORTA_TRAVE
	
	{ "fire/ignite" },						//	eSoundType_FIRE_IGNITE,
	{ "fire/fire" },						//	eSoundType_FIRE_FIRE,
	{ "damage/hurtflesh1", "damage/hurtflesh2", "damage/hurtflesh3" },				//	eSoundType_DAMAGE_HURT,
	{ "damage/fallsmall" },				//	eSoundType_DAMAGE_FA_SMA,
	{ "damage/fallbig1", "damage/fallbig2" },					//	eSoundType_DAMAGE_FA_BIG,
	{ "note/harp" },						//	eSoundType_NOTE_HARP,
	{ "note/bd" },							//	eSoundType_NOTE_BD,
	{ "note/snare" },						//	eSoundType_NOTE_SNARE,
	{ "note/hat" },						//	eSoundType_NOTE_HAT,
	{ "note/bassattack" },					//	eSoundType_NOTE_BASSATTACK,
	{ "tile/piston/in" },					//	eSoundType_TIE_PISTON_IN,
	{ "tile/piston/out" },					//	eSoundType_TIE_PISTON_OUT,
	{ "liquid/water" },					//	eSoundType_IQUID_WATER,
	{ "liquid/lavapop" },					//	eSoundType_IQUID_AVA_POP,
	{ "liquid/lava" },						//	eSoundType_IQUID_AVA,
	{ "step/stone1", "step/stone2", "step/stone3", "step/stone4", "step/stone5" },						//	eSoundType_STEP_STONE,
	{ "step/wood1", "step/wood2", "step/wood3", "step/wood4", "step/wood5", "step/wood6" },						//	eSoundType_STEP_WOOD,
	{ "step/gravel1", "step/gravel2", "step/gravel3", "step/gravel4" },						//	eSoundType_STEP_GRAVE,
	{ "step/grass1", "step/grass2", "step/grass3", "step/grass4", "step/grass5", "step/grass6" },						//	eSoundType_STEP_GRASS,
	{ "step/stone1" },						//	eSoundType_STEP_META,
	{ "step/cloth1", "step/cloth2", "step/cloth3", "step/cloth4" },						//	eSoundType_STEP_COTH,
	{ "step/sand1", "step/sand2", "step/sand3", "step/sand4", "step/sand5" },						//	eSoundType_STEP_SAND,
	
	// below this are the additional sounds from the second soundbank
	{ "mob/enderdragon/end" },				//	eSoundType_MOB_ENDERDRAGON_END
	{ "mob/enderdragon/growl1", "mob/enderdragon/growl2", "mob/enderdragon/growl3", "mob/enderdragon/growl4" },			//	eSoundType_MOB_ENDERDRAGON_GROW
	{ "mob/enderdragon/hit1", "mob/enderdragon/hit2", "mob/enderdragon/hit3", "mob/enderdragon/hit4" },				//	eSoundType_MOB_ENDERDRAGON_HIT
	{ "mob/enderdragon/wings1", "mob/enderdragon/wings2", "mob/enderdragon/wings3", "mob/enderdragon/wings4", "mob/enderdragon/wings5", "mob/enderdragon/wings6" },			//	eSoundType_MOB_ENDERDRAGON_MOVE
	{ "mob/irongolem/throw" },				//  eSoundType_MOB_IRONGOEM_THROW
	{ "mob/irongolem/hit1", "mob/irongolem/hit2", "mob/irongolem/hit3", "mob/irongolem/hit4" },				//  eSoundType_MOB_IRONGOEM_HIT
	{ "mob/irongolem/death" },				//  eSoundType_MOB_IRONGOEM_DEATH
	{ "mob/irongolem/walk1", "mob/irongolem/walk2", "mob/irongolem/walk3", "mob/irongolem/walk4" },				//  eSoundType_MOB_IRONGOEM_WAK

	// TU14
	{ "damage/hurtflesh1" },					//  eSoundType_DAMAGE_THORNS
	{ "random/anvil_break" },				//  eSoundType_RANDOM_ANVI_BREAK
	{ "random/anvil_land" },				//  eSoundType_RANDOM_ANVI_AND
	{ "random/anvil_use" },				//  eSoundType_RANDOM_ANVI_USE
	{ "mob/villager/haggle1", "mob/villager/haggle2", "mob/villager/haggle3" },				//  eSoundType_MOB_VIAGER_HAGGE
	{ "mob/villager/idle1", "mob/villager/idle2", "mob/villager/idle3" },				//  eSoundType_MOB_VIAGER_IDE
	{ "mob/villager/hit1", "mob/villager/hit2", "mob/villager/hit3", "mob/villager/hit4" },				//  eSoundType_MOB_VIAGER_HIT
	{ "mob/villager/death" },				//  eSoundType_MOB_VIAGER_DEATH
	{ "mob/villager/yes1", "mob/villager/yes2", "mob/villager/yes3" },				//  eSoundType_MOB_VIAGER_YES
	{ "mob/villager/no1", "mob/villager/no2", "mob/villager/no3" },					//  eSoundType_MOB_VIAGER_NO
	{ "mob/zombie/infect" },				//  eSoundType_MOB_ZOMBIE_INFECT
	{ "mob/zombie/unfect" },				//  eSoundType_MOB_ZOMBIE_UNFECT
	{ "mob/zombie/remedy" },				//  eSoundType_MOB_ZOMBIE_REMEDY
	{ "step/snow1", "step/snow2", "step/snow3", "step/snow4" },						//  eSoundType_STEP_SNOW
	{ "step/ladder1", "step/ladder2", "step/ladder3", "step/ladder4", "step/ladder5" },						//  eSoundType_STEP_ADDER
	{ "dig/cloth1", "dig/cloth2", "dig/cloth3", "dig/cloth4" },						//  eSoundType_DIG_COTH	
	{ "dig/grass1", "dig/grass2", "dig/grass3", "dig/grass4" },						//  eSoundType_DIG_GRASS	
	{ "dig/gravel1", "dig/gravel2", "dig/gravel3", "dig/gravel4" },						//  eSoundType_DIG_GRAVE	
	{ "dig/sand1", "dig/sand2", "dig/sand3", "dig/sand4" },						//  eSoundType_DIG_SAND	
	{ "dig/snow1", "dig/snow2", "dig/snow3", "dig/snow4" },						//  eSoundType_DIG_SNOW	
	{ "dig/stone1", "dig/stone2", "dig/stone3" },						//  eSoundType_DIG_STONE	
	{ "dig/wood1", "dig/wood2", "dig/wood3", "dig/wood4" },						//  eSoundType_DIG_WOOD	
};


/*const WCHAR *ConsoleSoundEngine::wchUISoundNames[eSFX_MAX]=
{
	"back",
	"craft",
	"craftfail",
	"focus",
	"press",
	"scroll",
};*/
