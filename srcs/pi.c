
#include "printf.h"

const char g_pi[139][72] = {
  "141592653589793238462643383279502884197169399375105820974944592307816406",
  "286208998628034825342117067982148086513282306647093844609550582231725359",
  "408128481117450284102701938521105559644622948954930381964428810975665933",
  "446128475648233786783165271201909145648566923460348610454326648213393607",
  "260249141273724587006606315588174881520920962829254091715364367892590360",
  "011330530548820466521384146951941511609433057270365759591953092186117381",
  "932611793105118548074462379962749567351885752724891227938183011949129833",
  "673362440656643086021394946395224737190702179860943702770539217176293176",
  "752384674818467669405132000568127145263560827785771342757789609173637178",
  "721468440901224953430146549585371050792279689258923542019956112129021960",
  "864034418159813629774771309960518707211349999998372978049951059731732816",
  "096318595024459455346908302642522308253344685035261931188171010003137838",
  "752886587533208381420617177669147303598253490428755468731159562863882353",
  "787593751957781857780532171226806613001927876611195909216420198938095257",
  "201065485863278865936153381827968230301952035301852968995773622599413891",
  "249721775283479131515574857242454150695950829533116861727855889075098381",
  "754637464939319255060400927701671139009848824012858361603563707660104710",
  "181942955596198946767837449448255379774726847104047534646208046684259069",
  "491233136770289891521047521620569660240580381501935112533824300355876402",
  "474964732639141992726042699227967823547816360093417216412199245863150302",
  "861829745557067498385054945885869269956909272107975093029553211653449872",
  "027559602364806654991198818347977535663698074265425278625518184175746728",
  "909777727938000816470600161452491921732172147723501414419735685481613611",
  "573525521334757418494684385233239073941433345477624168625189835694855620",
  "992192221842725502542568876717904946016534668049886272327917860857843838",
  "279679766814541009538837863609506800642251252051173929848960841284886269",
  "456042419652850222106611863067442786220391949450471237137869609563643719",
  "172874677646575739624138908658326459958133904780275900994657640789512694",
  "683983525957098258226205224894077267194782684826014769909026401363944374",
  "553050682034962524517493996514314298091906592509372216964615157098583874",
  "105978859597729754989301617539284681382686838689427741559918559252459539",
  "594310499725246808459872736446958486538367362226260991246080512438843904",
  "512441365497627807977156914359977001296160894416948685558484063534220722",
  "258284886481584560285060168427394522674676788952521385225499546667278239",
  "864565961163548862305774564980355936345681743241125150760694794510965960",
  "940252288797108931456691368672287489405601015033086179286809208747609178",
  "249385890097149096759852613655497818931297848216829989487226588048575640",
  "142704775551323796414515237462343645428584447952658678210511413547357395",
  "231134271661021359695362314429524849371871101457654035902799344037420073",
  "105785390621983874478084784896833214457138687519435064302184531910484810",
  "053706146806749192781911979399520614196634287544406437451237181921799983",
  "910159195618146751426912397489409071864942319615679452080951465502252316",
  "038819301420937621378559566389377870830390697920773467221825625996615014",
  "215030680384477345492026054146659252014974428507325186660021324340881907",
  "104863317346496514539057962685610055081066587969981635747363840525714591",
  "028970641401109712062804390397595156771577004203378699360072305587631763",
  "594218731251471205329281918261861258673215791984148488291644706095752706",
  "957220917567116722910981690915280173506712748583222871835209353965725121",
  "083579151369882091444210067510334671103141267111369908658516398315019701",
  "651511685171437657618351556508849099898599823873455283316355076479185358",
  "932261854896321329330898570642046752590709154814165498594616371802709819",
  "943099244889575712828905923233260972997120844335732654893823911932597463",
  "667305836041428138830320382490375898524374417029132765618093773444030707",
  "469211201913020330380197621101100449293215160842444859637669838952286847",
  "831235526582131449576857262433441893039686426243410773226978028073189154",
  "411010446823252716201052652272111660396665573092547110557853763466820653",
  "109896526918620564769312570586356620185581007293606598764861179104533488",
  "503461136576867532494416680396265797877185560845529654126654085306143444",
  "318586769751456614068007002378776591344017127494704205622305389945613140",
  "711270004078547332699390814546646458807972708266830634328587856983052358",
  "089330657574067954571637752542021149557615814002501262285941302164715509",
  "792592309907965473761255176567513575178296664547791745011299614890304639",
  "947132962107340437518957359614589019389713111790429782856475032031986915",
  "140287080859904801094121472213179476477726224142548545403321571853061422",
  "881375850430633217518297986622371721591607716692547487389866549494501146",
  "540628433663937900397692656721463853067360965712091807638327166416274888",
  "800786925602902284721040317211860820419000422966171196377921337575114959",
  "501566049631862947265473642523081770367515906735023507283540567040386743",
  "513622224771589150495309844489333096340878076932599397805419341447377441",
  "842631298608099888687413260472156951623965864573021631598193195167353812",
  "974167729478672422924654366800980676928238280689964004824354037014163149",
  "658979409243237896907069779422362508221688957383798623001593776471651228",
  "935786015881617557829735233446042815126272037343146531977774160319906655",
  "418763979293344195215413418994854447345673831624993419131814809277771038",
  "638773431772075456545322077709212019051660962804909263601975988281613323",
  "166636528619326686336062735676303544776280350450777235547105859548702790",
  "814356240145171806246436267945612753181340783303362542327839449753824372",
  "058353114771199260638133467768796959703098339130771098704085913374641442",
  "822772634659470474587847787201927715280731767907707157213444730605700733",
  "492436931138350493163128404251219256517980694113528013147013047816437885",
  "185290928545201165839341965621349143415956258658655705526904965209858033",
  "850722426482939728584783163057777560688876446248246857926039535277348030",
  "480290058760758251047470916439613626760449256274204208320856611906254543",
  "372131535958450687724602901618766795240616342522577195429162991930645537",
  "799140373404328752628889639958794757291746426357455254079091451357111369",
  "410911939325191076020825202618798531887705842972591677813149699009019211",
  "697173727847684726860849003377024242916513005005168323364350389517029893",
  "922334517220138128069650117844087451960121228599371623130171144484640903",
  "890644954440061986907548516026327505298349187407866808818338510228334508",
  "504860825039302133219715518430635455007668282949304137765527939751754613",
  "953984683393638304746119966538581538420568533862186725233402830871123282",
  "789212507712629463229563989898935821167456270102183564622013496715188190",
  "973038119800497340723961036854066431939509790190699639552453005450580685",
  "501956730229219139339185680344903982059551002263535361920419947455385938",
  "102343955449597783779023742161727111723643435439478221818528624085140066",
  "604433258885698670543154706965747458550332323342107301545940516553790686",
  "627333799585115625784322988273723198987571415957811196358330059408730681",
  "216028764962867446047746491599505497374256269010490377819868359381465741",
  "268049256487985561453723478673303904688383436346553794986419270563872931",
  "748723320837601123029911367938627089438799362016295154133714248928307220",
  "126901475466847653576164773794675200490757155527819653621323926406160136",
  "358155907422020203187277605277219005561484255518792530343513984425322341",
  "576233610642506390497500865627109535919465897514131034822769306247435363",
  "256916078154781811528436679570611086153315044521274739245449454236828860",
  "613408414863776700961207151249140430272538607648236341433462351897576645",
  "216413767969031495019108575984423919862916421939949072362346468441173940",
  "326591840443780513338945257423995082965912285085558215725031071257012668",
  "302402929525220118726767562204154205161841634847565169998116141010029960",
  "783869092916030288400269104140792886215078424516709087000699282120660418",
  "371806535567252532567532861291042487761825829765157959847035622262934860",
  "034158722980534989650226291748788202734209222245339856264766914905562842",
  "503912757710284027998066365825488926488025456610172967026640765590429099",
  "456815065265305371829412703369313785178609040708667114965583434347693385",
  "781711386455873678123014587687126603489139095620099393610310291616152881",
  "384379099042317473363948045759314931405297634757481193567091101377517210",
  "080315590248530906692037671922033229094334676851422144773793937517034436",
  "619910403375111735471918550464490263655128162288244625759163330391072253",
  "837421821408835086573917715096828874782656995995744906617583441375223970",
  "968340800535598491754173818839994469748676265516582765848358845314277568",
  "790029095170283529716344562129640435231176006651012412006597558512761785",
  "838292041974844236080071930457618932349229279650198751872127267507981255",
  "470958904556357921221033346697499235630254947802490114195212382815309114",
  "079073860251522742995818072471625916685451333123948049470791191532673430",
  "282441860414263639548000448002670496248201792896476697583183271314251702",
  "969234889627668440323260927524960357996469256504936818360900323809293459",
  "588970695365349406034021665443755890045632882250545255640564482465151875",
  "471196218443965825337543885690941130315095261793780029741207665147939425",
  "902989695946995565761218656196733786236256125216320862869222103274889218",
  "654364802296780705765615144632046927906821207388377814233562823608963208",
  "068222468012248261177185896381409183903673672220888321513755600372798394",
  "004152970028783076670944474560134556417254370906979396122571429894671543",
  "578468788614445812314593571984922528471605049221242470141214780573455105",
  "008019086996033027634787081081754501193071412233908663938339529425786905",
  "076431006383519834389341596131854347546495569781038293097164651438407007",
  "073604112373599843452251610507027056235266012764848308407611830130527932",
  "054274628654036036745328651057065874882256981579367897669742205750596834",
  "408697350201410206723585020072452256326513410559240190274216248439140359",
  "989535394590944070469120914093870012645600162374288021092764579310657922",
  "95524988727584610126483699989225695968815920560010165525637567856672279"};
