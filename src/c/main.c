#include <pebble.h>
#include <stdio.h>
#include <stdio.h>

Window *windowWakeup, *windowWakeup2, *windowWakeup3, *windowWakeup4, *windowWakeup5,
*windowClick, *windowClick2, *windowClick3, *windowClick4, *windowClick5;

TextLayer *text_layer, *text_layer2, *text_layer3, *text_layer4;

//Frequency
uint32_t freq_key = 1;
int freq = 0;

//Wakeup Time
uint32_t wakeup_key = 15;
int wakeup = 0;

//Bed Time
uint32_t bed_key = 30;
int bed = 0;



//First Reality check screen
void up_click_handler_Wakeup(ClickRecognizerRef recognizer, void *context)
{
  window_stack_push(windowWakeup2, true);
}

void down_click_handler_Wakeup(ClickRecognizerRef recognizer, void *context){}
 
void select_click_handler_Wakeup(ClickRecognizerRef recognizer, void *context){}

void click_config_provider_Wakeup(void *context)
{
    window_single_click_subscribe(BUTTON_ID_UP, up_click_handler_Wakeup);
    window_single_click_subscribe(BUTTON_ID_DOWN, down_click_handler_Wakeup);
    window_single_click_subscribe(BUTTON_ID_SELECT, select_click_handler_Wakeup);
}



//Second Reality Check screen
void up_click_handler_Wakeup2(ClickRecognizerRef recognizer, void *context)
{
  window_stack_push(windowWakeup3, true);
}

void down_click_handler_Wakeup2(ClickRecognizerRef recognizer, void *context)
{
   window_stack_push(windowWakeup4, true);
}
 
void select_click_handler_Wakeup2(ClickRecognizerRef recognizer, void *context){}

void click_config_provider_Wakeup2(void *context)
{
    window_single_click_subscribe(BUTTON_ID_UP, up_click_handler_Wakeup2);
    window_single_click_subscribe(BUTTON_ID_DOWN, down_click_handler_Wakeup2);
    window_single_click_subscribe(BUTTON_ID_SELECT, select_click_handler_Wakeup2);
}



//Third reality check screen
void up_click_handler_Wakeup3(ClickRecognizerRef recognizer, void *context)
{
  window_stack_push(windowWakeup4, true);
}

void down_click_handler_Wakeup3(ClickRecognizerRef recognizer, void *context)
{
   window_stack_push(windowWakeup5, true);
}
 
void select_click_handler_Wakeup3(ClickRecognizerRef recognizer, void *context){}

void click_config_provider_Wakeup3(void *context)
{
    window_single_click_subscribe(BUTTON_ID_UP, up_click_handler_Wakeup3);
    window_single_click_subscribe(BUTTON_ID_DOWN, down_click_handler_Wakeup3);
    window_single_click_subscribe(BUTTON_ID_SELECT, select_click_handler_Wakeup3);
}



//Settings Page 1: Frequency of reality checks
void up_click_handler_Click(ClickRecognizerRef recognizer, void *context) 
{
  freq = persist_read_int(freq_key);
  ++freq;
  persist_write_int(freq_key, freq);
  window_stack_push(windowClick, true);
}

void down_click_handler_Click(ClickRecognizerRef recognizer, void *context) 
{
  freq = persist_read_int(freq_key);
  --freq;
  persist_write_int(freq_key, freq);
  window_stack_push(windowClick, true); 
}

void select_click_handler_Click(ClickRecognizerRef recognizer, void *context) 
{
  persist_write_int(freq_key, freq);
  window_stack_push(windowClick2, true);
}

void click_config_provider_Click(void *context) 
{
  window_single_click_subscribe(BUTTON_ID_UP, up_click_handler_Click);
  window_single_click_subscribe(BUTTON_ID_DOWN, down_click_handler_Click);
  window_single_click_subscribe(BUTTON_ID_SELECT, select_click_handler_Click);
}



//Settings Page 2: Wakeup Time
void up_click_handler_Click2(ClickRecognizerRef recognizer, void *context) 
{
  wakeup = persist_read_int(wakeup_key);
  
  wakeup = wakeup + 15;
  
  if (wakeup%100 == 60){
    wakeup = wakeup + 40;
  }
  else if (wakeup > 2400){
    wakeup = 15;
  }
  
  persist_write_int(wakeup_key, wakeup);
  window_stack_push(windowClick2, true);  
}

void down_click_handler_Click2(ClickRecognizerRef recognizer, void *context) 
{
  wakeup = persist_read_int(wakeup_key);
  
  wakeup = wakeup - 15;
  
  if (wakeup%100 == 85){
    wakeup = wakeup - 40;
  }
  else if (wakeup < 15){
    wakeup = 2400;
  }
  
  persist_write_int(wakeup_key, wakeup);
  window_stack_push(windowClick2, true);  
}

void select_click_handler_Click2(ClickRecognizerRef recognizer, void *context) 
{
  persist_write_int(wakeup_key, wakeup);
  window_stack_push(windowClick3, true);
}

void click_config_provider_Click2(void *context) 
{
  window_single_click_subscribe(BUTTON_ID_UP, up_click_handler_Click2);
  window_single_click_subscribe(BUTTON_ID_DOWN, down_click_handler_Click2);
  window_single_click_subscribe(BUTTON_ID_SELECT, select_click_handler_Click2);
}


//Settings Page 3: Sleep time
void up_click_handler_Click3(ClickRecognizerRef recognizer, void *context) 
{
  bed = persist_read_int(bed_key);
  
  bed = bed + 15;
  
  if (bed%100 == 60){
    bed = bed + 40;
  }
  else if (bed > 2400){
    bed = 15;
  }
  
  persist_write_int(bed_key, bed);
  window_stack_push(windowClick3, true); 
}

void down_click_handler_Click3(ClickRecognizerRef recognizer, void *context) 
{
  bed = persist_read_int(bed_key);
  
  bed = bed - 15;
  
  if (bed%100 == 85){
    bed = bed - 40;
  }
  else if (bed < 15){
    bed = 2400;
  }
  
  persist_write_int(bed_key, bed);
  window_stack_push(windowClick3, true);
}

void select_click_handler_Click3(ClickRecognizerRef recognizer, void *context) 
{
  persist_write_int(bed_key, bed);
  window_stack_push(windowClick4, true);
}

void click_config_provider_Click3(void *context) 
{
  window_single_click_subscribe(BUTTON_ID_UP, up_click_handler_Click3);
  window_single_click_subscribe(BUTTON_ID_DOWN, down_click_handler_Click3);
  window_single_click_subscribe(BUTTON_ID_SELECT, select_click_handler_Click3);
}

void up_click_handler_Click4(ClickRecognizerRef recognizer, void *context) 
{
  window_stack_push(windowClick5, true);
}

void down_click_handler_Click4(ClickRecognizerRef recognizer, void *context) 
{
  
}

void select_click_handler_Click4(ClickRecognizerRef recognizer, void *context) 
{
  
}

void click_config_provider_Click4(void *context) 
{
  window_single_click_subscribe(BUTTON_ID_UP, up_click_handler_Click4);
  window_single_click_subscribe(BUTTON_ID_DOWN, down_click_handler_Click4);
  window_single_click_subscribe(BUTTON_ID_SELECT, select_click_handler_Click4);
}

//Wakeup 1
void window_load_Wakeup(Window *window)
{
  text_layer = text_layer_create(GRect(5,5,80,158));
  text_layer_set_background_color(text_layer, GColorBabyBlueEyes);
  text_layer_set_text_color(text_layer, GColorBlue);
  text_layer_set_font(text_layer, fonts_get_system_font(FONT_KEY_GOTHIC_18_BOLD));
  
  text_layer2 = text_layer_create(GRect(95,0,53,42));
  text_layer_set_background_color(text_layer2, GColorClear);
  text_layer_set_text_color(text_layer2, GColorBlue);
  text_layer_set_font(text_layer2, fonts_get_system_font(FONT_KEY_GOTHIC_24_BOLD));
  
  text_layer3 = text_layer_create(GRect(95,126,53,42));
  text_layer_set_background_color(text_layer3, GColorClear);
  text_layer_set_text_color(text_layer3, GColorBlue);
  text_layer_set_font(text_layer3, fonts_get_system_font(FONT_KEY_GOTHIC_24_BOLD));
  
  layer_add_child(window_get_root_layer(window), text_layer_get_layer(text_layer));
  layer_add_child(window_get_root_layer(window), text_layer_get_layer(text_layer2));
  layer_add_child(window_get_root_layer(window), text_layer_get_layer(text_layer3));
  text_layer_set_text(text_layer, "Time for a reality check! Click Yes to start.");
  text_layer_set_text(text_layer2, "Yes!");
  text_layer_set_text(text_layer3, "No.");
}

void window_unload_Wakeup(Window *window) 
{
  text_layer_destroy(text_layer);
  text_layer_destroy(text_layer2);
  text_layer_destroy(text_layer3);
}


//Wakeup 2
void window_load_Wakeup2(Window *window)
{
  text_layer = text_layer_create(GRect(5,5,80,158));
  text_layer_set_background_color(text_layer, GColorBabyBlueEyes);
  text_layer_set_text_color(text_layer, GColorBlue);
  text_layer_set_font(text_layer, fonts_get_system_font(FONT_KEY_GOTHIC_18_BOLD));
  
  text_layer2 = text_layer_create(GRect(95,0,53,42));
  text_layer_set_background_color(text_layer2, GColorClear);
  text_layer_set_text_color(text_layer2, GColorBlue);
  text_layer_set_font(text_layer2, fonts_get_system_font(FONT_KEY_GOTHIC_24_BOLD));
  
  text_layer3 = text_layer_create(GRect(95,126,53,42));
  text_layer_set_background_color(text_layer3, GColorClear);
  text_layer_set_text_color(text_layer3, GColorBlue);
  text_layer_set_font(text_layer3, fonts_get_system_font(FONT_KEY_GOTHIC_24_BOLD));
  
  layer_add_child(window_get_root_layer(window), text_layer_get_layer(text_layer));
  layer_add_child(window_get_root_layer(window), text_layer_get_layer(text_layer2));
  layer_add_child(window_get_root_layer(window), text_layer_get_layer(text_layer3));
  text_layer_set_text(text_layer, "Do you have 10 fingers?");
  text_layer_set_text(text_layer2, "Yes!");
  text_layer_set_text(text_layer3, "No.");
}

void window_unload_Wakeup2(Window *window) 
{
  text_layer_destroy(text_layer);
  text_layer_destroy(text_layer2);
  text_layer_destroy(text_layer3);
}



//Wakeup 3
void window_load_Wakeup3(Window *window)
{
  text_layer = text_layer_create(GRect(5,5,80,158));
  text_layer_set_background_color(text_layer, GColorBabyBlueEyes);
  text_layer_set_text_color(text_layer, GColorBlue);
  text_layer_set_font(text_layer, fonts_get_system_font(FONT_KEY_GOTHIC_18_BOLD));
  
  text_layer2 = text_layer_create(GRect(95,0,53,42));
  text_layer_set_background_color(text_layer2, GColorClear);
  text_layer_set_text_color(text_layer2, GColorBlue);
  text_layer_set_font(text_layer2, fonts_get_system_font(FONT_KEY_GOTHIC_24_BOLD));
  
  text_layer3 = text_layer_create(GRect(95,126,53,42));
  text_layer_set_background_color(text_layer3, GColorClear);
  text_layer_set_text_color(text_layer3, GColorBlue);
  text_layer_set_font(text_layer3, fonts_get_system_font(FONT_KEY_GOTHIC_24_BOLD));
  
  layer_add_child(window_get_root_layer(window), text_layer_get_layer(text_layer));
  layer_add_child(window_get_root_layer(window), text_layer_get_layer(text_layer2));
  layer_add_child(window_get_root_layer(window), text_layer_get_layer(text_layer3));
  text_layer_set_text(text_layer, "Can you press your finger through your palm?");
  text_layer_set_text(text_layer2, "Yes!");
  text_layer_set_text(text_layer3, "No.");
}

void window_unload_Wakeup3(Window *window) 
{
  text_layer_destroy(text_layer);
  text_layer_destroy(text_layer2);
  text_layer_destroy(text_layer3);
}


//Wakeup 4
void window_load_Wakeup4(Window *window)
{
  text_layer = text_layer_create(GRect(0,50,144,50));
  text_layer_set_background_color(text_layer, GColorClear);
  text_layer_set_text_color(text_layer, GColorBlue);
  text_layer_set_font(text_layer, fonts_get_system_font(FONT_KEY_GOTHIC_18_BOLD));
  
  layer_add_child(window_get_root_layer(window), text_layer_get_layer(text_layer));
  text_layer_set_text(text_layer, "You are dreaming!");
}

void window_unload_Wakeup4(Window *window) 
{
  text_layer_destroy(text_layer);
}


//Wakeup 5
void window_load_Wakeup5(Window *window)
{
  text_layer = text_layer_create(GRect(0,50,144,50));
  text_layer_set_background_color(text_layer, GColorClear);
  text_layer_set_text_color(text_layer, GColorBlue);
  text_layer_set_font(text_layer, fonts_get_system_font(FONT_KEY_GOTHIC_18));
  
  layer_add_child(window_get_root_layer(window), text_layer_get_layer(text_layer));
  text_layer_set_text(text_layer, "You are awake!");
}

void window_unload_Wakeup5(Window *window) 
{
  text_layer_destroy(text_layer);
  text_layer_destroy(text_layer2);
  text_layer_destroy(text_layer3);
}


//Settings: Frequency
void window_load_Click(Window *window) 
{
  text_layer = text_layer_create(GRect(5,5,105,158));
  text_layer_set_background_color(text_layer, GColorBabyBlueEyes);
  text_layer_set_text_color(text_layer, GColorBlue);
  text_layer_set_font(text_layer, fonts_get_system_font(FONT_KEY_GOTHIC_18));
  
  text_layer2 = text_layer_create(GRect(120,0,48,42));
  text_layer_set_background_color(text_layer2, GColorClear);
  text_layer_set_text_color(text_layer2, GColorBlue);
  text_layer_set_font(text_layer2, fonts_get_system_font(FONT_KEY_GOTHIC_24_BOLD));
  
  text_layer3 = text_layer_create(GRect(120,126,48,42));
  text_layer_set_background_color(text_layer3, GColorClear);
  text_layer_set_text_color(text_layer3, GColorBlue);
  text_layer_set_font(text_layer3, fonts_get_system_font(FONT_KEY_GOTHIC_24_BOLD));
  
  layer_add_child(window_get_root_layer(window), text_layer_get_layer(text_layer));
  layer_add_child(window_get_root_layer(window), text_layer_get_layer(text_layer2));
  layer_add_child(window_get_root_layer(window), text_layer_get_layer(text_layer3));
  text_layer_set_text(text_layer, "How many times a day would you like to receive reality checks?");
  text_layer_set_text(text_layer2, "+");
  text_layer_set_text(text_layer3, "-");
  
  text_layer4 = text_layer_create(GRect(56,96,48,42));
  text_layer_set_background_color(text_layer4, GColorClear);
  text_layer_set_text_color(text_layer4, GColorBlueMoon);
  text_layer_set_font(text_layer4, fonts_get_system_font(FONT_KEY_GOTHIC_24_BOLD));
  layer_add_child(window_get_root_layer(window), text_layer_get_layer(text_layer4));
  
  /* The string/char-buffer to hold the string representation of int.
   * Assuming a 4byte int, this needs to be a maximum of upto 12bytes.
   * to hold the number, optional negative sign and the NUL-terminator.
   */
  static char buf[] = "00000000000";    /* <-- implicit NUL-terminator at the end here */

  freq = persist_read_int(freq_key);
  snprintf(buf, sizeof(buf), "%d", freq);

/* buf now contains the string representation of int i
 * i.e. {'4', '2', 'NUL', ... }
 */
  text_layer_set_text(text_layer4, buf);
}

void window_unload_Click(Window *window) {
  text_layer_destroy(text_layer);
  text_layer_destroy(text_layer2);
  text_layer_destroy(text_layer3);
  text_layer_destroy(text_layer4);
}


//Settings: Wakeup time
void window_load_Click2(Window *window) 
{
  text_layer = text_layer_create(GRect(5,5,105,158));
  text_layer_set_background_color(text_layer, GColorBabyBlueEyes);
  text_layer_set_text_color(text_layer, GColorBlue);
  text_layer_set_font(text_layer, fonts_get_system_font(FONT_KEY_GOTHIC_18));
  
  text_layer2 = text_layer_create(GRect(120,0,48,42));
  text_layer_set_background_color(text_layer2, GColorClear);
  text_layer_set_text_color(text_layer2, GColorBlue);
  text_layer_set_font(text_layer2, fonts_get_system_font(FONT_KEY_GOTHIC_24_BOLD));
  
  text_layer3 = text_layer_create(GRect(120,126,48,42));
  text_layer_set_background_color(text_layer3, GColorClear);
  text_layer_set_text_color(text_layer3, GColorBlue);
  text_layer_set_font(text_layer3, fonts_get_system_font(FONT_KEY_GOTHIC_24_BOLD));
  
  layer_add_child(window_get_root_layer(window), text_layer_get_layer(text_layer));
  layer_add_child(window_get_root_layer(window), text_layer_get_layer(text_layer2));
  layer_add_child(window_get_root_layer(window), text_layer_get_layer(text_layer3));
  text_layer_set_text(text_layer, "What time do you normally wake up?");
  text_layer_set_text(text_layer2, "+");
  text_layer_set_text(text_layer3, "-");
  
  text_layer4 = text_layer_create(GRect(56,96,48,42));
  text_layer_set_background_color(text_layer4, GColorClear);
  text_layer_set_text_color(text_layer4, GColorBlueMoon);
  text_layer_set_font(text_layer4, fonts_get_system_font(FONT_KEY_GOTHIC_24_BOLD));
   layer_add_child(window_get_root_layer(window), text_layer_get_layer(text_layer4));
  
/* The string/char-buffer to hold the string representation of int.
 * Assuming a 4byte int, this needs to be a maximum of upto 12bytes.
 * to hold the number, optional negative sign and the NUL-terminator.
 */
  static char buf[] = "00000000000";    /* <-- implicit NUL-terminator at the end here */

  wakeup = persist_read_int(wakeup_key);
  snprintf(buf, sizeof(buf), "%d", wakeup);

/* buf now contains the string representation of int i
 * i.e. {'4', '2', 'NUL', ... }
 */
  text_layer_set_text(text_layer4, buf);
}

void window_unload_Click2(Window *window) {
  text_layer_destroy(text_layer);
  text_layer_destroy(text_layer2);
  text_layer_destroy(text_layer3);
  text_layer_destroy(text_layer4);
}


//Settings: Sleep time
void window_load_Click3(Window *window) 
{
  text_layer = text_layer_create(GRect(5,5,105,158));
  text_layer_set_background_color(text_layer, GColorBabyBlueEyes);
  text_layer_set_text_color(text_layer, GColorBlue);
  text_layer_set_font(text_layer, fonts_get_system_font(FONT_KEY_GOTHIC_18));
  
  text_layer2 = text_layer_create(GRect(120,0,48,42));
  text_layer_set_background_color(text_layer2, GColorClear);
  text_layer_set_text_color(text_layer2, GColorBlue);
  text_layer_set_font(text_layer2, fonts_get_system_font(FONT_KEY_GOTHIC_24_BOLD));
  
  text_layer3 = text_layer_create(GRect(120,126,48,42));
  text_layer_set_background_color(text_layer3, GColorClear);
  text_layer_set_text_color(text_layer3, GColorBlue);
  text_layer_set_font(text_layer3, fonts_get_system_font(FONT_KEY_GOTHIC_24_BOLD));
  
  layer_add_child(window_get_root_layer(window), text_layer_get_layer(text_layer));
  layer_add_child(window_get_root_layer(window), text_layer_get_layer(text_layer2));
  layer_add_child(window_get_root_layer(window), text_layer_get_layer(text_layer3));
  text_layer_set_text(text_layer, "What time do you normally go to bed?");
  text_layer_set_text(text_layer2, "+");
  text_layer_set_text(text_layer3, "-");
  
  text_layer4 = text_layer_create(GRect(56,96,48,42));
  text_layer_set_background_color(text_layer4, GColorClear);
  text_layer_set_text_color(text_layer4, GColorBlueMoon);
  text_layer_set_font(text_layer4, fonts_get_system_font(FONT_KEY_GOTHIC_24_BOLD));
  layer_add_child(window_get_root_layer(window), text_layer_get_layer(text_layer4));
  
  /* The string/char-buffer to hold the string representation of int.
 * Assuming a 4byte int, this needs to be a maximum of upto 12bytes.
 * to hold the number, optional negative sign and the NUL-terminator.
 */
  static char buf[] = "00000000000";    /* <-- implicit NUL-terminator at the end here */

  bed = persist_read_int(bed_key);
  snprintf(buf, sizeof(buf), "%d", bed);

/* buf now contains the string representation of int i
 * i.e. {'4', '2', 'NUL', ... }
 */
  text_layer_set_text(text_layer4, buf);
}

void window_unload_Click3(Window *window) {
  text_layer_destroy(text_layer);
  text_layer_destroy(text_layer2);
  text_layer_destroy(text_layer3);
  text_layer_destroy(text_layer4);
}

  //Settings apply? page
void window_load_Click4(Window *window) 
{
  text_layer = text_layer_create(GRect(5,5,91,158));
  text_layer_set_background_color(text_layer, GColorBabyBlueEyes);
  text_layer_set_text_color(text_layer, GColorBlue);
  text_layer_set_font(text_layer, fonts_get_system_font(FONT_KEY_GOTHIC_24_BOLD));
  
  text_layer2 = text_layer_create(GRect(101,0,48,42));
  text_layer_set_background_color(text_layer2, GColorClear);
  text_layer_set_text_color(text_layer2, GColorBlue);
  text_layer_set_font(text_layer2, fonts_get_system_font(FONT_KEY_GOTHIC_24_BOLD));
  
  text_layer3 = text_layer_create(GRect(101,126,48,42));
  text_layer_set_background_color(text_layer3, GColorClear);
  text_layer_set_text_color(text_layer3, GColorBlue);
  text_layer_set_font(text_layer3, fonts_get_system_font(FONT_KEY_GOTHIC_24_BOLD));
  
  layer_add_child(window_get_root_layer(window), text_layer_get_layer(text_layer));
  layer_add_child(window_get_root_layer(window), text_layer_get_layer(text_layer2));
  layer_add_child(window_get_root_layer(window), text_layer_get_layer(text_layer3));
  text_layer_set_text(text_layer, "Apply settings?");
  text_layer_set_text(text_layer2, "Yes!");
  text_layer_set_text(text_layer3, "No.");
}

void window_unload_Click4(Window *window) {
  text_layer_destroy(text_layer);
  text_layer_destroy(text_layer2);
  text_layer_destroy(text_layer3);
}


void window_load_Click5(Window *window) 
{
  text_layer = text_layer_create(GRect(50,50,50,50));
  text_layer_set_background_color(text_layer, GColorClear);
  text_layer_set_text_color(text_layer, GColorBlue);
  text_layer_set_font(text_layer, fonts_get_system_font(FONT_KEY_GOTHIC_24_BOLD));
  
  layer_add_child(window_get_root_layer(window), text_layer_get_layer(text_layer));

  text_layer_set_text(text_layer, "DONE!");
}

void window_unload_Click5(Window *window) {
  text_layer_destroy(text_layer);
}

void init() 
{
  
  //Initialize user preferences
  //Frequency
  if (persist_exists(freq_key)) {
    // Read persisted value
    freq = persist_read_int(freq_key);
  }   else {
    // Choose a default value
    freq = 4;

    // Remember the default value until the user chooses their own value
    persist_write_int(freq_key, freq);
  }
  
  //Wakeup time
  if (persist_exists(wakeup_key)) {
    // Read persisted value
    wakeup = persist_read_int(wakeup_key);
  }   else {
    // Choose a default value
    wakeup = 830;

    // Remember the default value until the user chooses their own value
    persist_write_int(wakeup_key, wakeup);
  }
  
   //Bed time
  if (persist_exists(bed_key)) {
    // Read persisted value
    bed = persist_read_int(bed_key);
  }   else {
    // Choose a default value
    bed = 2230;

    // Remember the default value until the user chooses their own value
    persist_write_int(bed_key, wakeup);
  }
  
  if (launch_reason() == APP_LAUNCH_WAKEUP) {
    vibes_short_pulse();
    //app was started by wakeup
    // Let the timestamp be 2 hours from now
    time_t future_timestamp = time(NULL) + (1 * SECONDS_PER_MINUTE);

    // Choose a 'cookie' value representing the reason for the wakeup
    const int cookie = 0;

    // If true, the user will be notified if they missed the wakeup 
    // (i.e. their watch was off)
    const bool notify_if_missed = true;

    // Schedule wakeup event
    WakeupId id = wakeup_schedule(future_timestamp, cookie, notify_if_missed);

    // Check the scheduling was successful
    if(id >= 0) {
      // Persist the ID so that a future launch can query it
      const int wakeup_id_key = 43;
      persist_write_int(wakeup_id_key, id);
    }
    windowWakeup = window_create();
    window_set_window_handlers(windowWakeup, (WindowHandlers) {
      .load = window_load_Wakeup,
      .unload = window_unload_Wakeup,
    });
    windowWakeup2 = window_create();
    window_set_window_handlers(windowWakeup2, (WindowHandlers) {
      .load = window_load_Wakeup2,
      .unload = window_unload_Wakeup2,
    });
    windowWakeup3 = window_create();
    window_set_window_handlers(windowWakeup3, (WindowHandlers) {
      .load = window_load_Wakeup3,
      .unload = window_unload_Wakeup3,
    });
    windowWakeup4 = window_create();
    window_set_window_handlers(windowWakeup4, (WindowHandlers) {
      .load = window_load_Wakeup4,
      .unload = window_unload_Wakeup4,
    });
    windowWakeup5 = window_create();
    window_set_window_handlers(windowWakeup5, (WindowHandlers) {
      .load = window_load_Wakeup5,
      .unload = window_unload_Wakeup5,
    });
    window_set_click_config_provider(windowWakeup, click_config_provider_Wakeup);
    window_set_click_config_provider(windowWakeup2, click_config_provider_Wakeup2);
    window_set_click_config_provider(windowWakeup3, click_config_provider_Wakeup3);
    window_stack_push(windowWakeup, true);
  } else {

     time_t future_timestamp = time(NULL) + (1 * SECONDS_PER_MINUTE);

     // Choose a 'cookie' value representing the reason for the wakeup
     const int cookie = 0;

     // If true, the user will be notified if they missed the wakeup 
     // (i.e. their watch was off)
     const bool notify_if_missed = true;

     // Schedule wakeup event
     WakeupId id = wakeup_schedule(future_timestamp, cookie, notify_if_missed);

     // Check the scheduling was successful
     if(id >= 0) {
        //Persist the ID so that a future launch can query it
       const int wakeup_id_key = 43;
       persist_write_int(wakeup_id_key, id);
     }
        
    windowClick = window_create();
    window_set_window_handlers(windowClick, (WindowHandlers) {
      .load = window_load_Click,
      .unload = window_unload_Click,
    });
    
    windowClick2 = window_create();
    window_set_window_handlers(windowClick2, (WindowHandlers) {
      .load = window_load_Click2,
      .unload = window_unload_Click2,
    });
    
    windowClick3 = window_create();
    window_set_window_handlers(windowClick3, (WindowHandlers) {
      .load = window_load_Click3,
      .unload = window_unload_Click3,
    });
    
    windowClick4 = window_create();
    window_set_window_handlers(windowClick4, (WindowHandlers) {
      .load = window_load_Click4,
      .unload = window_unload_Click4,
    });
    
    windowClick5 = window_create();
    window_set_window_handlers(windowClick5, (WindowHandlers) {
      .load = window_load_Click5,
      .unload = window_unload_Click5,
    });
    
    window_set_click_config_provider(windowClick, click_config_provider_Click);
    window_set_click_config_provider(windowClick2, click_config_provider_Click2);
    window_set_click_config_provider(windowClick3, click_config_provider_Click3);
    window_set_click_config_provider(windowClick4, click_config_provider_Click4);
    window_stack_push(windowClick, true);
  }
}

void deinit() 
{
  //deinitialize app elements
  window_destroy(windowWakeup);
  window_destroy(windowWakeup2);
  window_destroy(windowWakeup3);
  window_destroy(windowWakeup4);
  window_destroy(windowWakeup5);
  window_destroy(windowClick);
  window_destroy(windowClick2);
  window_destroy(windowClick3);
  window_destroy(windowClick4);
  window_destroy(windowClick5);
}

int main(void) 
{
  init();
  app_event_loop();
  deinit();
}






