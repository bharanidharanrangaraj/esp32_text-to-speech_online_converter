/* 
* Project Title: ESP32 based Text to Speech offline converter
*/

#include <Talkie.h>
#include "Vocab_US_Large.h"  // Include the vocab you want

Talkie voice;

// Minimal mapping: text → LPC array
struct WordMap {
  const char* text;
  const unsigned char* lpc;
};

// Only include words actually in your LPC vocab
WordMap words[] = {
    {"ZERO", sp2_ZERO},
    {"ONE", sp2_ONE},
    {"TWO", sp2_TWO},
    {"THREE", sp2_THREE},
    {"FOUR", sp2_FOUR},
    {"FIVE", sp2_FIVE},
    {"SIX", sp2_SIX},
    {"SEVEN", sp2_SEVEN},
    {"EIGHT", sp2_EIGHT},
    {"NINE", sp2_NINE},
    {"TEN", sp2_TEN},
    {"ELEVEN", sp2_ELEVEN},
    {"TWELVE", sp2_TWELVE},
    {"TWENTY", sp2_TWENTY},
    {"HUNDRED", sp2_HUNDRED},
    {"THOUSAND", sp2_THOUSAND},
    {"THIR", sp2_THIR_},
    {"FIF", sp2_FIF_},
    {"TEEN", sp2__TEEN},

    // Letters
    {"A", sp2_A},
    {"B", sp2_B},
    {"C", sp2_C},
    {"D", sp2_D},
    {"E", sp2_E},
    {"F", sp2_F},
    {"G", sp2_G},
    {"H", sp2_H},
    {"I", sp2_I},
    {"J", sp2_J},
    {"K", sp2_K},
    {"L", sp2_L},
    {"M", sp2_M},
    {"N", sp2_N},
    {"O", sp2_O},
    {"P", sp2_P},
    {"Q", sp2_Q},
    {"R", sp2_R},
    {"S", sp2_S},
    {"T", sp2_T},
    {"U", sp2_U},
    {"V", sp2_V},
    {"W", sp2_W},
    {"X", sp2_X},
    {"Y", sp2_Y},
    {"Z", sp2_Z},

    // Phonetic alphabet
    {"ALPHA", sp2_ALPHA},
    {"BRAVO", sp2_BRAVO},
    {"CHARLIE", sp2_CHARLIE},
    {"DELTA", sp2_DELTA},
    {"ECHO", sp2_ECHO},
    {"FOXTROT", sp2_FOXTROT},
    {"GOLF", sp2_GOLF},
    {"HENRY", sp2_HENRY},
    {"INDIA", sp2_INDIA},
    {"JULIET", sp2_JULIET},
    {"KILO", sp2_KILO},
    {"LIMA", sp2_LIMA},
    {"MIKE", sp2_MIKE},
    {"NOVEMBER", sp2_NOVEMBER},
    {"OSCAR", sp2_OSCAR},
    {"PAPA", sp2_PAPA},
    {"QUEBEC", sp2_QUEBEC},
    {"ROMEO", sp2_ROMEO},
    {"SIERRA", sp2_SIERRA},
    {"TANGO", sp2_TANGO},
    {"UNIFORM", sp2_UNIFORM},
    {"VICTOR", sp2_VICTOR},
    {"WHISKY", sp2_WHISKY},
    {"XRAY", sp2_XRAY},
    {"YANKEE", sp2_YANKEE},
    {"ZULU", sp2_ZULU},

    // Common words
    {"THE", sp2_THE},
    {"WATTS", sp2_WATTS},
    {"METER", sp2_METER},
    {"DANGER", sp2_DANGER},
    {"PRESSURE", sp2_PRESSURE},
    {"CHANGE", sp2_CHANGE},
    {"MINUS", sp2_MINUS},
    {"NOT", sp2_NOT},
    {"START", sp2_START},
    {"LINE", sp2_LINE},
    {"OFF", sp2_OFF},
    {"TIME", sp2_TIME},
    {"AUTOMATIC", sp2_AUTOMATIC},
    {"WEIGHT", sp2_WEIGHT},
    {"SMOKE", sp2_SMOKE},
    {"ABORT", sp2_ABORT},
    {"CALL", sp2_CALL},
    {"CYCLE", sp2_CYCLE},
    {"DISPLAY", sp2_DISPLAY},
    {"EQUAL", sp2_EQUAL},
    {"FAST", sp2_FAST},
    {"ABOUT", sp2_ABOUT},
    {"GO", sp2_GO},
    {"INCH", sp2_INCH},
    {"LOW", sp2_LOW},
    {"MOTOR", sp2_MOTOR},
    {"OPEN", sp2_OPEN},
    {"PERCENT", sp2_PERCENT},
    {"PROBE", sp2_PROBE},
    {"READY", sp2_READY},
    {"SET", sp2_SET},
    {"SPEED", sp2_SPEED},
    {"UNDER", sp2_UNDER},
    {"OPERATOR", sp2_OPERATOR},
    {"AMPS", sp2_AMPS},
    {"MEGA", sp2_MEGA},
    {"PICO", sp2_PICO},
    {"FIRE", sp2_FIRE},
    {"POWER", sp2_POWER},
    {"COMPLETE", sp2_COMPLETE},
    {"REPAIR", sp2_REPAIR},
    {"TEMPERATURE", sp2_TEMPERATURE},
    {"STOP", sp2_STOP},
    {"MACHINE", sp2_MACHINE},
    {"ON", sp2_ON},
    {"CONTROL", sp2_CONTROL},
    {"ELECTRICIAN", sp2_ELECTRICIAN},
    {"AT", sp2_AT},
    {"RED", sp2_RED},
    {"ALL", sp2_ALL},
    {"CANCEL", sp2_CANCEL},
    {"PHASE", sp2_PHASE},
    {"NOR", sp2_NOR},
    {"EXIT", sp2_EXIT},
    {"FLOW", sp2_FLOW},
    {"GAUGE", sp2_GAUGE},
    {"GREEN", sp2_GREEN},
    {"INSPECTOR", sp2_INSPECTOR},
    {"MANUAL", sp2_MANUAL},
    {"MOVE", sp2_MOVE},
    {"OVER", sp2_OVER},
    {"PLUS", sp2_PLUS},
    {"PULL", sp2_PULL},
    {"REPEAT", sp2_REPEAT},
    {"SHUT", sp2_SHUT},
    {"TEST", sp2_TEST},
    {"VOLTS", sp2_VOLTS},
    {"GALLONS", sp2_GALLONS},
    {"HERTZ", sp2_HERTZ},
    {"MICRO", sp2_MICRO},
    {"OHMS", sp2_OHMS},
    {"AREA", sp2_AREA},
    {"AND", sp2_AND},
    {"CIRCUIT", sp2_CIRCUIT},
    {"CONNECT", sp2_CONNECT},
    {"SECONDS", sp2_SECONDS},
    {"UNIT", sp2_UNIT},
    {"TIMER", sp2_TIMER},
    {"UP", sp2_UP},
    {"IS", sp2_IS},
    {"ALERT", sp2_ALERT},
    {"ADJUST", sp2_ADJUST},
    {"BETWEEN", sp2_BETWEEN},
    {"MINUTES", sp2_MINUTES},
    {"BUTTON", sp2_BUTTON},
    {"CLOCK", sp2_CLOCK},
    {"DEVICE", sp2_DEVICE},
    {"EAST", sp2_EAST},
    {"FAIL", sp2_FAIL},
    {"FREQUENCY", sp2_FREQUENCY},
    {"GATE", sp2_GATE},
    {"HIGH", sp2_HIGH},
    {"INTRUDER", sp2_INTRUDER},
    {"MEASURE", sp2_MEASURE},
    {"NORTH", sp2_NORTH},
    {"PASS", sp2_PASS},
    {"POSITION", sp2_POSITION},
    {"PUSH", sp2_PUSH},
    {"RIGHT", sp2_RIGHT},
    {"SLOW", sp2_SLOW},
    {"TOOL", sp2_TOOL},
    {"WEST", sp2_WEST},
    {"FARAD", sp2_FARAD},
    {"MILLI", sp2_MILLI},
    {"CAUTION", sp2_CAUTION},
    {"LIGHT", sp2_LIGHT},
    {"CHECK", sp2_CHECK},
    {"DEGREES", sp2_DEGREES},
    {"SERVICE", sp2_SERVICE},
    {"SWITCH", sp2_SWITCH},
    {"VALVE", sp2_VALVE},
    {"VAL", sp2_VAL},
    {"NUMBER", sp2_NUMBER},
    {"OUT", sp2_OUT},
    {"POINT", sp2_POINT},
    {"BREAK", sp2_BREAK},
    {"HOURS", sp2_HOURS},
    {"CALIBRATE", sp2_CALIBRATE},
    {"CRANE", sp2_CRANE},
    {"DIRECTION", sp2_DIRECTION},
    {"ENTER", sp2_ENTER},
    {"FEET", sp2_FEET},
    {"FROM", sp2_FROM},
    {"GAP", sp2_GAP},
    {"HOLD", sp2_HOLD},
    {"LEFT", sp2_LEFT},
    {"MILL", sp2_MILL},
    {"UH", sp2_UH},
    {"PAST", sp2_PAST},
    {"PRESS", sp2_PRESS},
    {"RANGE", sp2_RANGE},
    {"SAFE", sp2_SAFE},
    {"SOUTH", sp2_SOUTH},
    {"TURN", sp2_TURN},
    {"YELLOW", sp2_YELLOW},
    {"YELLOW", sp2_YELLOW},
};

const int wordCount = sizeof(words) / sizeof(words[0]);

void speakWord(const char* w) {
  for (int i = 0; i < wordCount; i++) {
    if (strcasecmp(w, words[i].text) == 0) {
      voice.say(words[i].lpc);
      return;
    }
  }
  Serial.print("Word not found in vocab: ");
  Serial.println(w);
}

void setup() {
  Serial.begin(9600);
  Serial.println("Type your sentence in capital letters. Example: HELLO WORLD");
}

void loop() {
  if (Serial.available() > 0) {
    String line = Serial.readStringUntil('\n');
    line.trim();
    line.toUpperCase();

    // Split sentence into words
    int start = 0;
    for (int i = 0; i <= line.length(); i++) {
      if (i == line.length() || line[i] == ' ') {
        String w = line.substring(start, i);
        speakWord(w.c_str());
        start = i + 1;
      }
    }
  }
}
