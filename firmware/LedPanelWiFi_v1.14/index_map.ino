#if (MATRIX_INDEX == 0)

// Примеры карты индексов для матриц размером 16x16, 32x8 и составной 48x16 (из 16x16, 32x8, 32x8)

#if (WIDTH == 16 && HEIGHT == 16)
#define INDEX_MAP_OK
bool loadIndexMap() {  
  String tmp(WIDTH); tmp += 'x'; tmp += HEIGHT;
  mapFiles[0] = tmp; 
  mapListLen = 1; 
  return true; 
}

// Матрица 16x16, мз 4-х матриц 8х8, угол подключения каждого сегмента - правый нижний, направление из угла - влево, тип - зигзаг
/* !!! Не удалять. Это информация о распределении сегментов матрицы !!!
>2222222211111111222222221111111122222222111111112222222211111111
 2222222211111111222222221111111122222222111111112222222A11111119
 7777777700000000777777770000000077777777000000007777777700000000
 7777777700000000777777770000000077777777000000007777777F00000008<
*/
const int16_t PROGMEM imap[] = {
   56,  57,  58,  59,  60,  61,  62,  63, 120, 121, 122, 123, 124, 125, 126, 127, 
   55,  54,  53,  52,  51,  50,  49,  48, 119, 118, 117, 116, 115, 114, 113, 112, 
   40,  41,  42,  43,  44,  45,  46,  47, 104, 105, 106, 107, 108, 109, 110, 111, 
   39,  38,  37,  36,  35,  34,  33,  32, 103, 102, 101, 100,  99,  98,  97,  96, 
   24,  25,  26,  27,  28,  29,  30,  31,  88,  89,  90,  91,  92,  93,  94,  95, 
   23,  22,  21,  20,  19,  18,  17,  16,  87,  86,  85,  84,  83,  82,  81,  80, 
    8,   9,  10,  11,  12,  13,  14,  15,  72,  73,  74,  75,  76,  77,  78,  79, 
    7,   6,   5,   4,   3,   2,   1,   0,  71,  70,  69,  68,  67,  66,  65,  64, 
  184, 185, 186, 187, 188, 189, 190, 191, 248, 249, 250, 251, 252, 253, 254, 255, 
  183, 182, 181, 180, 179, 178, 177, 176, 247, 246, 245, 244, 243, 242, 241, 240, 
  168, 169, 170, 171, 172, 173, 174, 175, 232, 233, 234, 235, 236, 237, 238, 239, 
  167, 166, 165, 164, 163, 162, 161, 160, 231, 230, 229, 228, 227, 226, 225, 224, 
  152, 153, 154, 155, 156, 157, 158, 159, 216, 217, 218, 219, 220, 221, 222, 223, 
  151, 150, 149, 148, 147, 146, 145, 144, 215, 214, 213, 212, 211, 210, 209, 208, 
  136, 137, 138, 139, 140, 141, 142, 143, 200, 201, 202, 203, 204, 205, 206, 207, 
  135, 134, 133, 132, 131, 130, 129, 128, 199, 198, 197, 196, 195, 194, 193, 192
};
#endif

#if (WIDTH == 32 && HEIGHT == 8)
#define INDEX_MAP_OK
bool loadIndexMap() {  
  String tmp(WIDTH); tmp += 'x'; tmp += HEIGHT;
  mapFiles[0] = tmp; 
  mapListLen = 1; 
  return true; 
}
// Матрица 32x8, угол подключения правый нижний, направление из угла - влево, тип - зигзаг
const int16_t PROGMEM imap[] = {
  224, 225, 226, 227, 228, 229, 230, 231, 232, 233, 234, 235, 236, 237, 238, 239, 240, 241, 242, 243, 244, 245, 246, 247, 248, 249, 250, 251, 252, 253, 254, 255, 
  223, 222, 221, 220, 219, 218, 217, 216, 215, 214, 213, 212, 211, 210, 209, 208, 207, 206, 205, 204, 203, 202, 201, 200, 199, 198, 197, 196, 195, 194, 193, 192, 
  160, 161, 162, 163, 164, 165, 166, 167, 168, 169, 170, 171, 172, 173, 174, 175, 176, 177, 178, 179, 180, 181, 182, 183, 184, 185, 186, 187, 188, 189, 190, 191, 
  159, 158, 157, 156, 155, 154, 153, 152, 151, 150, 149, 148, 147, 146, 145, 144, 143, 142, 141, 140, 139, 138, 137, 136, 135, 134, 133, 132, 131, 130, 129, 128, 
   96,  97,  98,  99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123, 124, 125, 126, 127, 
   95,  94,  93,  92,  91,  90,  89,  88,  87,  86,  85,  84,  83,  82,  81,  80,  79,  78,  77,  76,  75,  74,  73,  72,  71,  70,  69,  68,  67,  66,  65,  64, 
   32,  33,  34,  35,  36,  37,  38,  39,  40,  41,  42,  43,  44,  45,  46,  47,  48,  49,  50,  51,  52,  53,  54,  55,  56,  57,  58,  59,  60,  61,  62,  63, 
   31,  30,  29,  28,  27,  26,  25,  24,  23,  22,  21,  20,  19,  18,  17,  16,  15,  14,  13,  12,  11,  10,   9,   8,   7,   6,   5,   4,   3,   2,   1,   0
};
#endif

#if (WIDTH == 32 && HEIGHT == 16)
#define INDEX_MAP_OK
bool loadIndexMap() {  
  String tmp(WIDTH); tmp += 'x'; tmp += HEIGHT;
  mapFiles[0] = tmp; 
  mapListLen = 1; 
  return true; 
}
// Матрица сборная из двух 16x16, у обеих матриц угол подключения левый нижний, направление вправо, тип - зигзаг
/* !!! Не удалять. Это информация о распределении сегментов матрицы !!!
>00000000000000001111111111111111000000000000000011111111111111110000000000000000111111111111111100000000000000001111111111111111
 00000000000000001111111111111111000000000000000011111111111111110000000000000000111111111111111100000000000000001111111111111111
 00000000000000001111111111111111000000000000000011111111111111110000000000000000111111111111111100000000000000001111111111111111
 00000000000000001111111111111111000000000000000011111111111111110000000000000000111111111111111180000000000000009111111111111111<
*/
const int16_t PROGMEM imap[] = {
  255, 254, 253, 252, 251, 250, 249, 248, 247, 246, 245, 244, 243, 242, 241, 240, 511, 510, 509, 508, 507, 506, 505, 504, 503, 502, 501, 500, 499, 498, 497, 496, 
  224, 225, 226, 227, 228, 229, 230, 231, 232, 233, 234, 235, 236, 237, 238, 239, 480, 481, 482, 483, 484, 485, 486, 487, 488, 489, 490, 491, 492, 493, 494, 495, 
  223, 222, 221, 220, 219, 218, 217, 216, 215, 214, 213, 212, 211, 210, 209, 208, 479, 478, 477, 476, 475, 474, 473, 472, 471, 470, 469, 468, 467, 466, 465, 464, 
  192, 193, 194, 195, 196, 197, 198, 199, 200, 201, 202, 203, 204, 205, 206, 207, 448, 449, 450, 451, 452, 453, 454, 455, 456, 457, 458, 459, 460, 461, 462, 463, 
  191, 190, 189, 188, 187, 186, 185, 184, 183, 182, 181, 180, 179, 178, 177, 176, 447, 446, 445, 444, 443, 442, 441, 440, 439, 438, 437, 436, 435, 434, 433, 432, 
  160, 161, 162, 163, 164, 165, 166, 167, 168, 169, 170, 171, 172, 173, 174, 175, 416, 417, 418, 419, 420, 421, 422, 423, 424, 425, 426, 427, 428, 429, 430, 431, 
  159, 158, 157, 156, 155, 154, 153, 152, 151, 150, 149, 148, 147, 146, 145, 144, 415, 414, 413, 412, 411, 410, 409, 408, 407, 406, 405, 404, 403, 402, 401, 400, 
  128, 129, 130, 131, 132, 133, 134, 135, 136, 137, 138, 139, 140, 141, 142, 143, 384, 385, 386, 387, 388, 389, 390, 391, 392, 393, 394, 395, 396, 397, 398, 399, 
  127, 126, 125, 124, 123, 122, 121, 120, 119, 118, 117, 116, 115, 114, 113, 112, 383, 382, 381, 380, 379, 378, 377, 376, 375, 374, 373, 372, 371, 370, 369, 368, 
   96,  97,  98,  99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 352, 353, 354, 355, 356, 357, 358, 359, 360, 361, 362, 363, 364, 365, 366, 367, 
   95,  94,  93,  92,  91,  90,  89,  88,  87,  86,  85,  84,  83,  82,  81,  80, 351, 350, 349, 348, 347, 346, 345, 344, 343, 342, 341, 340, 339, 338, 337, 336, 
   64,  65,  66,  67,  68,  69,  70,  71,  72,  73,  74,  75,  76,  77,  78,  79, 320, 321, 322, 323, 324, 325, 326, 327, 328, 329, 330, 331, 332, 333, 334, 335, 
   63,  62,  61,  60,  59,  58,  57,  56,  55,  54,  53,  52,  51,  50,  49,  48, 319, 318, 317, 316, 315, 314, 313, 312, 311, 310, 309, 308, 307, 306, 305, 304, 
   32,  33,  34,  35,  36,  37,  38,  39,  40,  41,  42,  43,  44,  45,  46,  47, 288, 289, 290, 291, 292, 293, 294, 295, 296, 297, 298, 299, 300, 301, 302, 303, 
   31,  30,  29,  28,  27,  26,  25,  24,  23,  22,  21,  20,  19,  18,  17,  16, 287, 286, 285, 284, 283, 282, 281, 280, 279, 278, 277, 276, 275, 274, 273, 272, 
    0,   1,   2,   3,   4,   5,   6,   7,   8,   9,  10,  11,  12,  13,  14,  15, 256, 257, 258, 259, 260, 261, 262, 263, 264, 265, 266, 267, 268, 269, 270, 271
};
#endif

#if (WIDTH == 48 && HEIGHT == 16)
#define INDEX_MAP_OK
bool loadIndexMap() {  
  String tmp(WIDTH); tmp += 'x'; tmp += HEIGHT;
  mapFiles[0] = tmp; 
  mapListLen = 1; 
  return true; 
}
// Матрица 48x16 из матрицы 16x16 и двух матриц 32x8, 
// +----+----+---------------+
// |         |      #3       |
// |    #1   +---------------+
// |         |      #2       |
// +----+----+---------------+
// угол подключения матрицы #1 - правый нижний, направление из угла - влево, тип - зигзаг
// угол подключения матрицы #2 - левый нижний,  направление из угла - вверх, тип - зигзаг
// угол подключения матрицы #3 - левый верхний, направление из угла - вниз,  тип - зигзаг
/* !!! Не удалять. Это информация о распределении сегментов матрицы !!!
>0000000000000000E666666666666666666666666666666600000000000000006666666666666666666666666666666600000000000000006666666666666666
 66666666666666660000000000000000666666666666666666666666666666660000000000000000666666666666666666666666666666660000000000000000
 66666666666666666666666666666666000000000000000066666666666666666666666666666666000000000000000066666666666666666666666666666666
 00000000000000001111111111111111111111111111111100000000000000001111111111111111111111111111111100000000000000001111111111111111
 11111111111111110000000000000000111111111111111111111111111111110000000000000000111111111111111111111111111111110000000000000000
 11111111111111111111111111111111000000000000000011111111111111111111111111111111000000000000000891111111111111111111111111111111<
*/
const int16_t PROGMEM imap[] = {
  240, 241, 242, 243, 244, 245, 246, 247, 248, 249, 250, 251, 252, 253, 254, 255, 512, 527, 528, 543, 544, 559, 560, 575, 576, 591, 592, 607, 608, 623, 624, 639, 640, 655, 656, 671, 672, 687, 688, 703, 704, 719, 720, 735, 736, 751, 752, 767, 
  239, 238, 237, 236, 235, 234, 233, 232, 231, 230, 229, 228, 227, 226, 225, 224, 513, 526, 529, 542, 545, 558, 561, 574, 577, 590, 593, 606, 609, 622, 625, 638, 641, 654, 657, 670, 673, 686, 689, 702, 705, 718, 721, 734, 737, 750, 753, 766, 
  208, 209, 210, 211, 212, 213, 214, 215, 216, 217, 218, 219, 220, 221, 222, 223, 514, 525, 530, 541, 546, 557, 562, 573, 578, 589, 594, 605, 610, 621, 626, 637, 642, 653, 658, 669, 674, 685, 690, 701, 706, 717, 722, 733, 738, 749, 754, 765, 
  207, 206, 205, 204, 203, 202, 201, 200, 199, 198, 197, 196, 195, 194, 193, 192, 515, 524, 531, 540, 547, 556, 563, 572, 579, 588, 595, 604, 611, 620, 627, 636, 643, 652, 659, 668, 675, 684, 691, 700, 707, 716, 723, 732, 739, 748, 755, 764, 
  176, 177, 178, 179, 180, 181, 182, 183, 184, 185, 186, 187, 188, 189, 190, 191, 516, 523, 532, 539, 548, 555, 564, 571, 580, 587, 596, 603, 612, 619, 628, 635, 644, 651, 660, 667, 676, 683, 692, 699, 708, 715, 724, 731, 740, 747, 756, 763, 
  175, 174, 173, 172, 171, 170, 169, 168, 167, 166, 165, 164, 163, 162, 161, 160, 517, 522, 533, 538, 549, 554, 565, 570, 581, 586, 597, 602, 613, 618, 629, 634, 645, 650, 661, 666, 677, 682, 693, 698, 709, 714, 725, 730, 741, 746, 757, 762, 
  144, 145, 146, 147, 148, 149, 150, 151, 152, 153, 154, 155, 156, 157, 158, 159, 518, 521, 534, 537, 550, 553, 566, 569, 582, 585, 598, 601, 614, 617, 630, 633, 646, 649, 662, 665, 678, 681, 694, 697, 710, 713, 726, 729, 742, 745, 758, 761, 
  143, 142, 141, 140, 139, 138, 137, 136, 135, 134, 133, 132, 131, 130, 129, 128, 519, 520, 535, 536, 551, 552, 567, 568, 583, 584, 599, 600, 615, 616, 631, 632, 647, 648, 663, 664, 679, 680, 695, 696, 711, 712, 727, 728, 743, 744, 759, 760, 
  112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123, 124, 125, 126, 127, 263, 264, 279, 280, 295, 296, 311, 312, 327, 328, 343, 344, 359, 360, 375, 376, 391, 392, 407, 408, 423, 424, 439, 440, 455, 456, 471, 472, 487, 488, 503, 504, 
  111, 110, 109, 108, 107, 106, 105, 104, 103, 102, 101, 100,  99,  98,  97,  96, 262, 265, 278, 281, 294, 297, 310, 313, 326, 329, 342, 345, 358, 361, 374, 377, 390, 393, 406, 409, 422, 425, 438, 441, 454, 457, 470, 473, 486, 489, 502, 505, 
   80,  81,  82,  83,  84,  85,  86,  87,  88,  89,  90,  91,  92,  93,  94,  95, 261, 266, 277, 282, 293, 298, 309, 314, 325, 330, 341, 346, 357, 362, 373, 378, 389, 394, 405, 410, 421, 426, 437, 442, 453, 458, 469, 474, 485, 490, 501, 506, 
   79,  78,  77,  76,  75,  74,  73,  72,  71,  70,  69,  68,  67,  66,  65,  64, 260, 267, 276, 283, 292, 299, 308, 315, 324, 331, 340, 347, 356, 363, 372, 379, 388, 395, 404, 411, 420, 427, 436, 443, 452, 459, 468, 475, 484, 491, 500, 507, 
   48,  49,  50,  51,  52,  53,  54,  55,  56,  57,  58,  59,  60,  61,  62,  63, 259, 268, 275, 284, 291, 300, 307, 316, 323, 332, 339, 348, 355, 364, 371, 380, 387, 396, 403, 412, 419, 428, 435, 444, 451, 460, 467, 476, 483, 492, 499, 508, 
   47,  46,  45,  44,  43,  42,  41,  40,  39,  38,  37,  36,  35,  34,  33,  32, 258, 269, 274, 285, 290, 301, 306, 317, 322, 333, 338, 349, 354, 365, 370, 381, 386, 397, 402, 413, 418, 429, 434, 445, 450, 461, 466, 477, 482, 493, 498, 509, 
   16,  17,  18,  19,  20,  21,  22,  23,  24,  25,  26,  27,  28,  29,  30,  31, 257, 270, 273, 286, 289, 302, 305, 318, 321, 334, 337, 350, 353, 366, 369, 382, 385, 398, 401, 414, 417, 430, 433, 446, 449, 462, 465, 478, 481, 494, 497, 510, 
   15,  14,  13,  12,  11,  10,   9,   8,   7,   6,   5,   4,   3,   2,   1,   0, 256, 271, 272, 287, 288, 303, 304, 319, 320, 335, 336, 351, 352, 367, 368, 383, 384, 399, 400, 415, 416, 431, 432, 447, 448, 463, 464, 479, 480, 495, 496, 511
};
#endif

#ifndef INDEX_MAP_OK
#error Нет определения карты индексов для заданных WIDTH и HEIGHT
bool loadIndexMap() { return false; }
#endif




// =================================================================================================================================




#elif (MATRIX_INDEX == 1)

int16_t* imap; 

int8_t scanIndexMaps() {

  File entry;  
  uint32_t file_size;

  mapListLen = 0;
  
  DEBUGLN(F("Поиск файлов карт индексов..."));
  
  #if defined(ESP32)
    File folder = LittleFS.open("/");
  #else
    Dir  folder = LittleFS.openDir("/");
  #endif
    
  while (true) {

    #if defined(ESP32)
      entry = folder.openNextFile();
      if (!entry) break;
    #else        
      if (!folder.next()) break;
      entry = folder.openFile("r");
    #endif
                   
    if (!entry.isDirectory()) {
            
      file_size = entry.size();
      {
        String file_name(entry.name());  
        String fn(file_name);
        fn.toLowerCase();
        
        if (!fn.endsWith(".map") || file_size == 0) {
          entry.close();
          continue;    
        }
        
        // Если полученное имя файла содержит имя папки (на ESP32 это так, на ESP8266 - только имя файла) - оставить только имя файла
        int16_t p = file_name.lastIndexOf("/");
        if (p >= 0) file_name = file_name.substring(p + 1);
  
        DEBUG("   ");
        DEBUGLN(file_name);
  
        p = file_name.lastIndexOf(".");
        if (p >= 0) file_name = file_name.substring(0, p);
        mapFiles[mapListLen++] = file_name;
      }
      
      entry.close();

      if (mapListLen >= MAX_MAP_FILES) {
        DEBUG(F("Максимальное количество карт: "));        
        DEBUGLN(MAX_MAP_FILES);
        break;
      }      
    }
  }

  if (mapListLen == 0) { 
    DEBUGLN(F("Нет файлов карт индексов\n"));
  } else {
    DEBUGLN();
  }

  return mapListLen;  
}

bool loadIndexMap() {

  bool isLoaded = true;
  

  if (scanIndexMaps() == 0) {
    imap = NULL;
    return false;
  }
  
  // Создать массив индексов с текущими размерами матрицы, заполнить значениями -1
  imap = new int16_t[NUM_LEDS];
  for (int16_t i = 0; i < NUM_LEDS; i++) imap[i] = -1;

  String message;
    
  while (true) {

    String fileName(pWIDTH); fileName += 'x'; fileName += pHEIGHT; fileName += ".map";
    DEBUG(F("Загрузка файла индексов: "));
    DEBUG(fileName);
    DEBUGLN(F("..."));

    // Попытка открыть файл индексов на чтение
    fileName = "/" + fileName;
    File file = LittleFS.open(fileName, "r");
    if (!file) {
      message = F("Нет карты индексов для матрицы "); message += pWIDTH; message += 'x'; message += pHEIGHT;
      isLoaded = false;
      break;
    }
     
    uint8_t buf[2];

    // Сигнатура - 0xA5A5
    size_t  len = file.read(buf, 2);
    bool    ok = len == 2;
    if (!ok || !(buf[0] == 0xA5 && buf[1] == 0xA5)) {
      message = F("Неверный формат файла индексов.");
      isLoaded = false;
      break;
    }

    // Ширина и высота матрицы из файла
    len = file.read(buf, 2);
    ok = len == 2;
    uint8_t size_x = buf[0];
    uint8_t size_y = buf[1];
    
    if (!ok || !(size_x <= 128 && size_y <= 128)) {
      message = F("Неподдерживаемый размер матрицы в файле индексов: "); message += size_x; message += 'x'; message += size_y;
      isLoaded = false;
      break;
    }
    
    if (!ok || !(size_x == pWIDTH && size_y == pHEIGHT)) {
      message  = F("Размер матрицы в файле индексов не сооответствует настроенному размеру матрицы\n"); 
      message += F("Файл: "); message += size_x; message += 'x'; message += size_y; message += F("; Матрица: ");
      message += pWIDTH; message += 'x'; message += pHEIGHT;
      isLoaded = false;
      break;
    }

    for (uint16_t i = 0; i < NUM_LEDS; i++) {
      len = file.read(buf, 2);
      ok = len == 2;
      if (!ok) {
        message = F("Неверный формат файла индексов.");
        isLoaded = false;
        break;
      }
      imap[i] = (int16_t)(buf[1] << 8 | buf[0]);
    }    

    break;
  }
    
  // Если файла индексов для текущего размера матрицы не существует или не удалось загрузить -
  // сбросить тип адресации матрицы к значению по-умолчанию
  if (!isLoaded) {
    DEBUGLN(message);
    DEBUGLN(F("Ошибка загрузки файла карты индексов\n"));
    delete [] imap;
    imap = NULL;
  } else {
    DEBUGLN(F("Загрузка файла карты индексов завершена\n"));    
  }

  return isLoaded;
}

#endif
