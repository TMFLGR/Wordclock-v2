#ifndef clock_layout_h
#define clock_layout_h

/**     LED Layout, starting at bottom left, zigzagging upwards. 
 *      every char gets one led.
 *      
 *      E----S----K----I----S----T----E----F----Ü----N----F
 *      110  109       107  106  105       103  102  101  100
 * 
 *      U----N----D----J----Z----W----A----N----Z----I----G
 *      89   90   91        93   94   95   96   97   98   99 
 * 
 *      Z----E----H----N----V----I----E----R----T----E----L
 *      88   87   86   85   84   83   82   81   80   79   78
 * 
 *      V----O----R----H----A----L----B----N----A----C----H
 *      67   68   69   70   71   72   73   74   75   76   77
 * 
 *      N----E----U----N----F----L----O----F----Ü----N----F
 *      66   65   64   63                  59   58   57   56
 * 
 *      E----I----N----S----E----L----F----Z----W----E----I
 *      45   46   47   48   49   50   51   52   53   54   55  
 * 
 *      D----R----E----I----J----U----L----V----I----E----R
 *      44   43   42   41                  37   36   35   34
 * 
 *      S----E----C----H----S----N----L----A----C----H----T
 *      23   24   25   26   27   28        30   31   32   33
 * 
 *      S----I----E----B----E----N----Z----W----Ö----L----F
 *      22   21   20   19   18   17   16   15   14   13   12
 * 
 *      Z----E----H----N----I----L----Y----F----U----H----R
 *      1    2    3    4                        9    10   11
 */

int * init_array(int from, int to) {
    int * array = new int [size];
    if (to < from) {
        return array;
    }
    int size = (to - from) + 1;
    int temp = from;
    for (int i = 0; i < size; ++i) {
        array[i] = temp;
        ++temp;
    }
    return array;
}

static const int * WORD_ES = init_array(109, 110);
static const int * WORD_IST = init_array(105, 107);

static const int * WORD_IST = init_array(105, 106);
static const int * WORD_UHR = init_array(9, 11);

static const int * WORD_VOR = init_array(67, 69);
static const int * WORD_NACH = init_array(74, 77);
static const int * WORD_VIERTEL = init_array(78, 84);
static const int * WORD_HALB = init_array(70, 73);
static const int * WORD_UND = init_array(89, 91);

static const int * WORD_EIN = init_array(45, 47);
static const int * WORD_EINS = init_array(47, 48);
static const int * WORD_ZWEI = init_array(52, 55);
static const int * WORD_DREI = init_array(41, 44);
static const int * WORD_VIER = init_array(34, 37);

static const int * WORD_FUENF1 = init_array(100, 103);
static const int * WORD_FUENF2 = init_array(56, 59);

static const int * WORD_SECHS = init_array(23, 28);
static const int * WORD_SIEBEN = init_array(17, 22);
static const int * WORD_ACHT = init_array(30, 33);
static const int * WORD_NEUN = init_array(63, 66);

static const int * WORD_ZEHN1 = init_array(85, 88);
static const int * WORD_ZEHN2 = init_array(1, 4);

static const int * WORD_ELF = init_array(49, 51);
static const int * WORD_ZWOELF = init_array(12, 16);
static const int * WORD_ZWANZIG = init_array(93, 99);

#endif
