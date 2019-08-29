#include "printf.h"
/*
void    first_shift_80(char product[63][5000], t_float *fnum, unsigned int power)
{
  unsigned int offset;

  offset = 0;
  printf("result is %zu\n", ft_strlen(product[power + 16382]));
  if (fnum->remain & 1)
  {
    offset = power + 16382 - ft_strlen(product[power + 16382]);
    printf("offset is %u\n", offset);
    while (offset)
    {
      ft_strcat_char(fnum->big_str, '0');
      offset--;
    }
    printf("we got hereeee\n");
  ft_strcat(fnum->big_str, product[power + 16382]);
  }
}
*/
void    sum_power_80(char product[63][5000], t_float *fnum)
{
  int power;
  unsigned int carry;
  int i;

  power = 62;
  i = 4998;
  carry = 0;

  while (!(fnum->remain & 1))
  {
    fnum->remain >>= 1;
    power--;
  }
  ft_strcat(fnum->big_str, product[power]);
  fnum->remain >>= 1;
  power--;

  while (power >= 0)
  {
    if (fnum->remain & 1)
    {
      carry = 0;
      i = 4998;
      while (product[power][i])
      {
        fnum->big_str[i] += product[power][i] + carry - '0';
        carry = 0;
        if (fnum->big_str[i] > '9')
        {
          carry = 1;
          fnum->big_str[i] -= 10;
        }
        i--;
      }
    }
    fnum->remain >>= 1;
    power--;
  }
  printf("printing subnorminal number=%s\n",fnum->big_str);
}


void    aggregate_80(char product[63][5000])
{
    int i;
    int j;
    unsigned int tmp;
    unsigned int carry;

    i = 62; //index of last row is i = 62
    j = 4998; //j is index number of digit
    carry = 0;

    while (i > 0)  // index no. of 62-0 makes 63 rows
    {
      while(product[i][j])
      {
        tmp  = (product[i][j] - '0') * 2;
    //    printf("tmp = %u, i = %d, j = %d\n", tmp, i, j);
        product[i - 1][j] += carry + '0';
    //    printf("product[%d][%d] = %c\n", i + 1, j, product[i + 1][j]);
        carry = tmp / 10;
        tmp = tmp % 10;
        product[i - 1][j] += tmp;
        if (product[i - 1][j] > '9')
        {
          product[i - 1][j] -= 10;
          carry += 1;
        }
    //    printf("%c ", product[i + 1][j]);
        j--;
      }
      if (carry)
        product[i - 1][j] += carry + '0';
      carry = 0;

      j = 4998;
      i--;
    }

}
void    sub_array_80(t_float *fnum)
{
   // 50 rows, each 1000 characters long, fit till ^ 50
  char product[63][5000];
  int i;
  //long double seed;
  //changing algorithm : we only need the range from 2^-16383 to 2^-16445. so only need to *5 for 61 times the
  // non-zero parts in 2^-16383, then figure out how many zero offsets when you add,
  // and last job would be to pad all zeros in front.
  // algo for subnormal 80:
  i = 0;
  while (i < 64)
  {
    ft_bzero(&product[i], 5000);
    i++;
  }
  i = 0;
  while (i++ < 1358)
    ft_strcat_char(product[62], '0');
  printf("number of zeroes=%zu\n", ft_strlen("00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000"));
  ft_strcat(product[62], "36451995318824746025284059336194198163990508156935633437209804870283716886333977368095607086258272051972473473472035311019669856326220321699735080755898090054838225811779316785692252638056335597566215625659834107289403197935535272685912407999541728110155185383830460547687154224492953058597182682142626220675323554608440680792597537396882263389719028133546642119572938120002167626722920322774336390308456055297955188552992122553211711634876291384629300355138527501603132845785873465668580833490531237051939887039833085878399463225014686024594663765868704564236347102423971946588603575680671344779827642197362928177512955605368457612678466479085174632509237360395127227814159533660963994444034021170534884480219777636044379086876232490341169092945505322835546042550164710485109901552496948203761750727745215979248292641646728293792248343785221488475244616533404531408985349389010799994660849957929408670822251678980926263322841336335372303657106066727110161016969869085455268160934467855758235452864566704649092870630625875619302191928395746860797324007419326707925865842479032526017145025116520187337055564776698564030616718609883010220890087524042382938121214157585271795472816282327108859944585747150338528775954260248007917199819553441519165990035038288222003556659679587710909376884092310507637448820944563204842727161227981498363616605895952090835768872542325329552297498926405507629594382412784961938193820775459054611725479613404698176911656760942613207257273126074829376531404216196861030595291994214319374495660993373960630752183022438454753416779724620381266269034081670865175453863821550089560659554103929149526239278808471595331845354866664804805634075314283853293005224776842170509512647474546357548662147849415423151110386306843914252124393041905841223742229722846065374850524646486553697190990267605182875609969972107784730669801294274274395170323909647913676782217496309754197134381391626788785559991775284508827480465385881774472703067382348985029769028530013645504052272870939400583257885854573686549919562658630500834720876230660209033789194899209751908294216020103820394777720834006615191549726954365823050219109085766920481735349588941709767630848078374028138492275409420733154011152623348768159620874413022565584389125006072302057820130836741130234976124452147951709838486879883482032894412569087555652160818151512056388931125624153290844569340951461844692909011661106348755901648356069416294074897743797927398046747642434839120846918717692254465062843105653091908724772862559253835285450363605508542269195712463611332259048203019165883170843777122593678948464112948225870758354869856455108298805285787826984125562492745222350610924543423862023271204078275403339146131921891743158841366880194359662736634704314404430321364117756050306014368370639726903304174751873302009119675004967616181226147964529371240703987038908689155270514904657367453977649410948794796494381625766143469486520853080246963582567565857945684933190420538828438081803587871107744180754788011865195774162718963831698357082256365846545686437026186024335489381637207327725383454545130650115406757655106569705004135372053700679248802092173634073236733684480049044084139777417069654942470407997864518618221884735712575568194332840874860236762494678694836313804738564862395470156033183226127836520686997985394004066373116827311153406778416602407104315511403704103755855729393030840738435407021205519630505149599457413591699116765754784032793801120203473482925381507983204527948424275265017968529118631081782766384723202378700828622717633961951395137123031361943660215408305314569105840483725460251777651404602071129231519231764021467528682219668899153815");
  ft_strcat_char(product[62], '\0');
  printf("last char is %c\n", product[62][4999]);
  printf("second last char is %c\n", product[62][4998]);
  printf("length is %zu\n", ft_strlen(product[62]));
  aggregate_80(product);

/*
  i = 0;
  while(i < 1079)
  {
    printf("product[%d] is %s\n", i, product[i]);
    i++;
  }
*/
(void)fnum;
  sum_power_80(product, fnum);
  printf("\nwe got to the end\n");
}
