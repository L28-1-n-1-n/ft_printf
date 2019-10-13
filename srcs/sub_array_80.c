#include "printf.h"
#include <unistd.h>
#include <stdlib.h>
//#include "const.h"
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
}*/
//void    sum_power_80(char product[63][16427], t_float *fnum)
void    sum_power_80(char **product, t_float *fnum)
{
  int power;
  unsigned int carry;
  int i;

  power = 62;
  i = 16425;
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
      i = 16425;
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
//  printf("printing subnorminal number=%s\n",fnum->big_str);
/*  i = 0;
  while (i < 20000)
  {
    printf("%c-%d\t", fnum->big_str[i], i);
    i++;
  }
  printf("fnum->bigstr[%d] is %c\n", i - 1, fnum->big_str[i - 1]);*/
}


//void    aggregate_80(char product[63][16427])
void    aggregate_80(char **product)
{
    int i;
    int j;
    unsigned int tmp;
    unsigned int carry;

    i = 62; //index of last row is i = 62
    j = 16425; //j is index number of digit
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

      j = 16425;
      i--;
    }

}
void    sub_array_80(t_float *fnum)
{

  char **product;

  int i;
  i = 0;
  product = (char **)malloc(sizeof(char *) * 64);
  while (i < 64)
  {
    if (!(product[i]=(char*)ft_strnew(16426)))
      return ;
    i++;
  }
  i = 0;
  while (i < 64)
  {
    ft_strcpy(product[i], "\0");
    i++;
  }

  i = 0;

//  ft_strcpy(product[62],"0");

  while (i++ < 4931)
  {
    ft_strcat_char(product[62], '0');

  }
  printf("malloc complete\n");
  ft_strcat(product[62], "36451995318824746025284059336194198163990508156935633437209804870283716886333977368095607086258272051972473473472035311019669856326220321699735080755898090054838225811779316785692252638056335597566215625659834107289403197935535272685912407999541728110155185383830460547687154224492953058597182682142626220675323554608440680792597537396882263389719028133546642119572938120002167626722920322774336390308456055297955188552992122553211711634876291384629300355138527501603132845785873465668580833490531237051939887039833085878399463225014686024594663765868704564236347102423971946588603575680671344779827642197362928177512955605368457612678466479085174632509237360395127227814159533660963994444034021170534884480219777636044379086876232490341169092945505322835546042550164710485109901552496948203761750727745215979248292641646728293792248343785221488475244616533404531408985349389010799994660849957929408670822251678980926263322841336335372303657106066727110161016969869085455268160934467855758235452864566704649092870630625875619302191928395746860797324007419326707925865842479032526017145025116520187337055564776698564030616718609883010220890087524042382938121214157585271795472816282327108859944585747150338528775954260248007917199819553441519165990035038288222003556659679587710909376884092310507637448820944563204842727161227981498363616605895952090835768872542325329552297498926405507629594382412784961938193820775459054611725479613404698176911656760942613207257273126074829376531404216196861030595291994214319374495660993373960630752183022438454753416779724620381266269034081670865175453863821550089560659554103929149526239278808471595331845354866664804805634075314283853293005224776842170509512647474546357548662147849415423151110386306843914252124393041905841223742229722846065374850524646486553697190990267605182875609969972107784730669801294274274395170323909647913676782217496309754197134381391626788785559991775284508827480465385881774472703067382348985029769028530013645504052272870939400583257885854573686549919562658630500834720876230660209033789194899209751908294216020103820394777720834006615191549726954365823050219109085766920481735349588941709767630848078374028138492275409420733154011152623348768159620874413022565584389125006072302057820130836741130234976124452147951709838486879883482032894412569087555652160818151512056388931125624153290844569340951461844692909011661106348755901648356069416294074897743797927398046747642434839120846918717692254465062843105653091908724772862559253835285450363605508542269195712463611332259048203019165883170843777122593678948464112948225870758354869856455108298805285787826984125562492745222350610924543423862023271204078275403339146131921891743158841366880194359662736634704314404430321364117756050306014368370639726903304174751873302009119675004967616181226147964529371240703987038908689155270514904657367453977649410948794796494381625766143469486520853080246963582567565857945684933190420538828438081803587871107744180754788011865195774162718963831698357082256365846545686437026186024335489381637207327725383454545130650115406757655106569705004135372053700679248802092173634073236733684480049044084139777417069654942470407997864518618221884735712575568194332840874860236762494678694836313804738564862395470156033183226127836520686997985394004066373116827311153406778416602407104315511403704103755855729393030840738435407021205519630505149599457413591699116765754784032793801120203473482925381507983204527948424275265017968529118631081782766384723202378700828622717633961951395137123031361943660215408305314569105840483725460251777651404602071129231519231764021467528682219668899153815964812531606968222607231942595218130543034572223679679292687630728923552788547142782438631107830670601244590393155281768403049315228131487458243508921305950151980025572043324832155514470975125100762233648012028880876356506546349468872327276239064590766702271086341623192103570072733693546571875690463948848950837941035318359596139945753778977755254619774647475181629750100914635619250327426455946458005816006983478170231943799213973476811504926872373490215642064630961387032012502777579804107726470143915791444243752525197667646704580085152976476241448144534960696851274398006295520756926486086815068790443764289774631751752051815479584595151590747012858384936940340076624101001835331415166841854607581750664815610189011330319510420990532971188374489844432308566427376064787878802852999035218550256124134710344666241715592090775384984751068112940290603342718033205664939350246217197176848044433518669466905252660607583321905318072325655018902937542595909474331403843353669733988168992536983021199161428916310053493353721580057799445291767358871939804092884746216945903030985523823769694423651860231309855078236176700511918890153514796597786761324496716420150595404382373039229030560790683446354402767725654259443299276549062629524755557509120238794246360214620433216314283656758518656549016934743434114062209075500900456895883239368146751261034644012237280581850483204752512668828752991205822530900331778836744323438127341239220429265549085482314732853495722109622898898009940265336293214647005520293915172930551962180656672512762374901292060984143389032109424889027922539246679410822732675635286538633434434864957624004099789959850520823107302770769652428462784025682851873655888766532454230472059434786129319642112934893741195657514867872048845023075123729239731191911256140687560945268927833216880303109005580256834554518984874011393152907434774619210259879053322362993988594489387420874873162887307110687527634493923668972362589970911769962532843066876354543618621794071916521552436506195717202321286241307854049305668050292332713755462533132874462858122199615650226545103738705816482147911391708709705090741587219676334254715505158014981911072162776206923470142349135273858121648344750020070994021229914395427839819849271813006696032901904951061957842485312997402627061067983385735239773652409412936952141886756327154470813722525510229819212511256751318392100741322860296214432621271458720224043142582192556064152802184450746540347901150755585133744227536171881983859311648101828170027941722798030282020865670812674533493413454963892393797764944190223010420679866005010454669500040571347269341476916780319866988453702999870673844073103374338281165148307453744907601716721529785950403514055725265230260512150937099005678735683852425745463850085677382639515326765492943564175657977715956384967191495778042162918921255410551471737237449917566696724590213751112887541253729183944179762430930282147033293860317993139495351613438927204090460650099589809789479976625455146641942620976652972426123679687660006291746558870908243635836538436589802775660312864296284763185729150458238958058260101327129778344186134682888329885473771745507968025731486842532941722850567778269273771580586471454035577212335120024954373394139988427825997101862157234379581542753405098110723490410464838062846088733942757188785904186928092883334235227812406989744418298793037942414558527767133213548706472510947206755723227884479087787788921162341316176084167322809874931413318849278602593243927812557861508918592034972126159164049990970677787399148579613058849346787620435155211905818982566246359578309278114211549921399869999362036311498523728025643148961517493264044287720082504285693383296981618501712654114267081137235583250590628715067128384609860311470603514915063160125325387933544995456670095275738108920480046524524521396887893929129382518883412981222352328611387339031535609672921042411909463505167697693050307623869083995925550431922360692794912244658266842033120812554318517563412345669139725893906015586508304374020455952076899961595975457118082036883181129189476616621158029195786364034303230416100180636967072212498263837152633888503074184694239734867470092339450362209015181857669427338368461268166381583450487827282412512798203101932235129591110298840022305716882168542822578732186317444509505523274289525381495452627798898243990285131322086386330706021355227520766615678724723251256742912688818491014163827036474514282328479933321571807940150363653616458881463557493661502090854571891872327863995858799416803703481411054047422984524978953692871939744961404456773012714035896658229110968329520211813435711369576078163183427557705604065699202616339664034841216798695426848436869083543736884379686835257236661214859479467478875727163608006964428164741135934661060892041795546771453745824379626646188830186286875100795112525560022417883462840197508639922839065135723259180534640806435215321548250748202390779907790070695880340296195621904167473597128840843245215986781788901864094514806867817331768249202768350024775234860935869637331554244918975754958515495270345383376943149530571640192150266707739109974432797600052906415115847071932263512716704397751410765526327361661176113949343256737438823655183185612089415529316291251367997115745789167410235872514289989469631824116505544042064163364874186561053330385457739601909496028500962085690852302287088948745775235125582819733929612639216561639633693884117634763886259524069015182734130370686433835502829622377291959017885993928766510865998492239942591452592404793843806578034980587190625290073394283162299977568998577121169227586830717074729355744992449784197881713384684717511253038609115892894008066372029204294899198702634159516608889754348273042974513623250526934820015248431712290784679105379131381154586266120249707308995151143019152816139292393293515010498592252745641078468181129383391613089431532051176517163804684622961938824442933704843685300968988127789731782849127985502452460634119184826382616940292452732916467073315946752134281587552738824383579602450640510158889185418011397716197432214050377972856694814558106533200089042159975979759073915120262140200120101347075367742276364775809181675078504851970653263910911714517637512376127394984685100090554800250960159855817693701796567811513065659525901019773983351850426376819823064484137221778956652903027962230041985260791431040700078745405482215823473895787419076942400727481338608233691306518076204361009674221579290719040619858762532542927481005014913765764511576139421431541604676635409021586558797152327419024652190612044660693995435376237453269257301351968475833102403001369008236966611120591489492515903721090781653063244581176729675960068856111942740131146840740541811184282840103004930033587050301900280487212275329820719538229025584586853416012880693465359149039189696272389562977393988534711551019333954374699288583646053249971063453730263564728856760186110311977064212243833134357208256222160645522427147562668961335127742514704508066065350492888477275980124150117639708989422759831098626780358600183566986993645900959533847966610129802053717740681727113599896621245073184945019268969821281470919288094309836935086280049529210899513358900892946097845649234235447752769274825864761270613428690709421136820281174870155241002571199674103957710112670611141230259423720618775007941625687469437425631850080526365777429066862274710511444737925672781712002353779026307058832211008928435045237483068464864135552613382236283996029971083220897986305897891731966709434578109722499468955961728119019245987541050221232627731661646957854925001791688432728730998876898269318290667599988068020564509132663190036411682160975457987265596336140953842411883537930043774357363620998602506078671956559415254590575394512979922359917893695680863804210613237189662157069244179283987801793513468553063862900533945505275994496303948455562249364447779953479766845703125");

  printf("product[62] is %s\n", product[62]);
  ft_strcat_char(product[62], '\0');
aggregate_80(product);

(void)fnum;
  sum_power_80(product, fnum);
  /*  i = 0;
    while ((i < 20000) && (fnum->big_str[i] == '0'))
      i++;
    printf("i is %d\n", i);
    int j;
    j = ft_strlen(&fnum->big_str[i]);
    printf("j is %d\n", j);
    ft_memmove(&fnum->big_str[0], &fnum->big_str[i], ft_strlen(&fnum->big_str[i]));
    while (j < 20000)
    {
      fnum->big_str[j] = '\0';
      j++;
    }
*/
//  printf("fnum->big_str[16095] is %s\n", &fnum->big_str[16093]);
//  printf("size of big_str is %lu\n", sizeof(fnum->big_str));
/*  i = 0;
  while ((i < 20000) && (fnum->big_str[i] != '\0'))
  {
    write(1, &fnum->big_str[i], 1);
    i++;
  }*/
//  printf("last char is %s\n", &fnum->big_str[16425]);
//  printf("big_str is %s\n", fnum->big_str);
}
