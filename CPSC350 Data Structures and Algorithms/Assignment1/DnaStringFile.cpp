#include "DnaStringFile.h"
DnaStringFile::DnaStringFile(){}
DnaStringFile::~DnaStringFile(){}
bool DnaStringFile::open(string path) {
// See: http://stackoverflow.com/questions/12774207/fastest-way-to-check-if-a-file-exist-using-standard-c-c11-c
	struct stat buffer;   
	if (!(stat (path.c_str(), &buffer) == 0)) {
		cout<<"IOError: File does not exist."<<endl;
		return false;
	}
	f.open(path.c_str());
	return true;
}
void DnaStringFile::close() {
	f.close();
}
void DnaStringFile::computeStatistics() {
	string line;
	int numLines = 0;
	numChars = 0;
	int aa = 0;
	int ac = 0;
	int at = 0;
	int ag = 0;
	int ca = 0;
	int cc = 0;
	int ct = 0;
	int cg = 0;
	int ta = 0;
	int tc = 0;
	int tt = 0;
	int tg = 0;
	int ga = 0;
	int gc = 0;
	int gt = 0;
	int gg = 0;
	int a = 0;
	int c = 0;
	int t = 0;
	int g = 0;
	int totBigrams = 0;
	while (getline(f, line)) {
		int z = strlen(line.c_str());
		numChars = numChars+z;
		for (int i=0; i<z; ++i) { // loop until 2nd to last char
			char char1 = tolower(line.at(i));
			if (z==i+1) {
				if (char1 == 'a') {
					a++;
				} else if (char1 == 'c') {
					c++;
				} else if (char1 == 't') {
					t++;
				} else if (char1 == 'g') {
					g++;
				}
				break;
			}
			char char2 = tolower(line.at(i+1));
			// if-else block to count bigrams and single nucleotides
			if (char1=='a' && char2=='a') {
				aa++;
				a++;
			} else if (char1=='a' && char2=='c') {
				ac++;
				a++;
			} else if (char1=='a' && char2=='t') {
				at++;
				a++;
			} else if (char1=='a' && char2=='g') {
				ag++;
				a++;
			} else if (char1=='c' && char2=='a') {
				ca++;
				c++;
			} else if (char1=='c' && char2=='c') {
				cc++;
				c++;
			} else if (char1=='c' && char2=='t') {
				ct++;
				c++;
			} else if (char1=='c' && char2=='g') {
				cg++;
				c++;
			} else if (char1=='t' && char2=='a') {
				ta++;
				t++;
			} else if (char1=='t' && char2=='c') {
				tc++;
				t++;
			} else if (char1=='t' && char2=='t') {
				tt++;
				t++;
			} else if (char1=='t' && char2=='g') {
				tg++;
				t++;
			} else if (char1=='g' && char2=='a') {
				ga++;
				g++;
			} else if (char1=='g' && char2=='c') {
				gc++;
				g++;
			} else if (char1=='g' && char2=='t') {
				gt++;
				g++;
			} else if (char1=='g' && char2=='g') {
				gg++;
				g++;
			}
			totBigrams++;
		}
		numLines++;
	}
	// Calculate mean
	mean = (double)numChars/(double)numLines;
	// Calculate relative probability of single nucleotides
	pA = a/(double)numChars;
	pC = c/(double)numChars;
	pT = t/(double)numChars;
	pG = g/(double)numChars;

	// Calculate probability of bigrams in file
	pAA = aa/(double)totBigrams;
	pAC = ac/(double)totBigrams;
	pAT = at/(double)totBigrams;
	pAG = ag/(double)totBigrams;
	pCA = ca/(double)totBigrams;
	pCC = cc/(double)totBigrams;
	pCT = ct/(double)totBigrams;
	pCG = cg/(double)totBigrams;
	pTA = ta/(double)totBigrams;
	pTC = tc/(double)totBigrams;
	pTT = tt/(double)totBigrams;
	pTG = tg/(double)totBigrams;
	pGA = ga/(double)totBigrams;
	pGC = gc/(double)totBigrams;
	pGT = gt/(double)totBigrams;
	pGG = gg/(double)totBigrams;
	
	// Restart from beginning of file to loop through again
	f.clear();
	f.seekg(0, f.beg);

	// Calculate variance and standard deviation
	double sumSquares = 0;
	while (getline(f, line)) {
		int m = strlen(line.c_str()); // for each number
		double j = (double)m-(double)mean; // subtract the mean
		double n = pow(j,2.0); // and square the result
		sumSquares=sumSquares+n; // sum the squares

	}
	variance = (double)sumSquares/(double)numLines;
	stdDeviation = pow((double)variance,0.5);
}
void DnaStringFile::printStatisticsToFile() {
	ofstream o;
	o.open("xaviablaza.out", ofstream::out | ofstream::app);
	o<<"Xavi Ablaza\n";
	o<<"2258883\n";
	o<<"Sum: "<<numChars<<"\n";
	o<<"Mean: "<<mean<<"\n";
	o<<"Variance: "<<variance<<"\n";
	o<<"Standard Deviation: "<<stdDeviation<<"\n";
	o<<"A: "<< pA*100 << "%\n";
	o<<"C: "<< pC*100 << "%\n";
	o<<"T: "<< pT*100 << "%\n";
	o<<"G: "<< pG*100 << "%\n";
	o<<"AA: "<< pAA*100 << "%\n";
	o<<"AC: "<< pAC*100 << "%\n";
	o<<"AT: "<< pAT*100 << "%\n";
	o<<"AG: "<< pAG*100 << "%\n";
	o<<"CA: "<< pCA*100 << "%\n";
	o<<"CC: "<< pCC*100 << "%\n";
	o<<"CT: "<< pCT*100 << "%\n";
	o<<"CG: "<< pCG*100 << "%\n";
	o<<"TA: "<< pTA*100 << "%\n";
	o<<"TC: "<< pTC*100 << "%\n";
	o<<"TT: "<< pTT*100 << "%\n";
	o<<"TG: "<< pTG*100 << "%\n";
	o<<"GA: "<< pGA*100 << "%\n";
	o<<"GC: "<< pGC*100 << "%\n";
	o<<"GT: "<< pGT*100 << "%\n";
	o<<"GG: "<< pGG*100 << "%\n";
	o<<"---END SUMMARY STATISTICS---\n";
	o.close();
}
void DnaStringFile::printGaussianDnaString(int amount) {
	int rVarSum = 0;
	string rVars = "";
	int rv0 = 0;
	int rv1 = 0;
	int rv2 = 0;
	int rv3 = 0;
	int rv4 = 0;
	int rv5 = 0;
	int rv6 = 0;
	int rv7 = 0;
	int rv8 = 0;
	int rv9 = 0;
	int rv10 = 0;
	int rv11 = 0;
	int rv12 = 0;
	int rv13 = 0;
	int rv14 = 0;
	int rv15 = 0;
	int rv16 = 0;
	int rv17 = 0;
	int rv18 = 0;
	int rv19 = 0;
	int rv20 = 0;
	int rv21 = 0;
	int rv22 = 0;
	int rv23 = 0;
	int rv24 = 0;
	int rv25 = 0;
	int rv26 = 0;
	int rv27 = 0;
	int rv28 = 0;
	int rv29 = 0;
	int rv30 = 0;
	int rv31 = 0;
	int rv32 = 0;
	int rv33 = 0;
	int rv34 = 0;
	int rv35 = 0;
	int rv36 = 0;
	int rv37 = 0;
	int rv38 = 0;
	int rv39 = 0;
	int rv40 = 0;
	int rv41 = 0;
	int rv42 = 0;
	int rv43 = 0;
	int rv44 = 0;
	int rv45 = 0;
	int rv46 = 0;
	int rv47 = 0;
	int rv48 = 0;
	int rv49 = 0;
	int rv50 = 0;
	int rv51 = 0;
	int rv52 = 0;
	int rv53 = 0;
	int rv54 = 0;
	int rv55 = 0;
	int rv56 = 0;
	int rv57 = 0;
	int rv58 = 0;
	int rv59 = 0;
	int rv60 = 0;
	int rv61 = 0;
	int rv62 = 0;
	int rv63 = 0;
	int rv64 = 0;
	int rv65 = 0;
	int rv66 = 0;
	int rv67 = 0;
	int rv68 = 0;
	int rv69 = 0;
	int rv70 = 0;
	int rv71 = 0;
	int rv72 = 0;
	int rv73 = 0;
	int rv74 = 0;
	int rv75 = 0;
	int rv76 = 0;
	int rv77 = 0;
	int rv78 = 0;
	int rv79 = 0;
	int rv80 = 0;
	int rv81 = 0;
	int rv82 = 0;
	int rv83 = 0;
	int rv84 = 0;
	int rv85 = 0;
	int rv86 = 0;
	int rv87 = 0;
	int rv88 = 0;
	int rv89 = 0;
	int rv90 = 0;
	int rv91 = 0;
	int rv92 = 0;
	int rv93 = 0;
	int rv94 = 0;
	int rv95 = 0;
	int rv96 = 0;
	int rv97 = 0;
	int rv98 = 0;
	int rv99 = 0;
	int rv100 = 0;
	int rv101 = 0;
	int rv102 = 0;
	int rv103 = 0;
	int rv104 = 0;
	int rv105 = 0;
	int rv106 = 0;
	int rv107 = 0;
	int rv108 = 0;
	int rv109 = 0;
	int rv110 = 0;
	int rv111 = 0;
	int rv112 = 0;
	int rv113 = 0;
	int rv114 = 0;
	int rv115 = 0;
	int rv116 = 0;
	int rv117 = 0;
	int rv118 = 0;
	int rv119 = 0;
	int rv120 = 0;
	int rv121 = 0;
	int rv122 = 0;
	int rv123 = 0;
	int rv124 = 0;
	int rv125 = 0;
	int rv126 = 0;
	int rv127 = 0;
	int rv128 = 0;
	int rv129 = 0;
	int rv130 = 0;
	int rv131 = 0;
	int rv132 = 0;
	int rv133 = 0;
	int rv134 = 0;
	int rv135 = 0;
	int rv136 = 0;
	int rv137 = 0;
	int rv138 = 0;
	int rv139 = 0;
	int rv140 = 0;
	int rv141 = 0;
	int rv142 = 0;
	int rv143 = 0;
	int rv144 = 0;
	int rv145 = 0;
	int rv146 = 0;
	int rv147 = 0;
	int rv148 = 0;
	int rv149 = 0;
	int rv150 = 0;
	int rv151 = 0;
	int rv152 = 0;
	int rv153 = 0;
	int rv154 = 0;
	int rv155 = 0;
	int rv156 = 0;
	int rv157 = 0;
	int rv158 = 0;
	int rv159 = 0;
	int rv160 = 0;
	int rv161 = 0;
	int rv162 = 0;
	int rv163 = 0;
	int rv164 = 0;
	int rv165 = 0;
	int rv166 = 0;
	int rv167 = 0;
	int rv168 = 0;
	int rv169 = 0;
	int rv170 = 0;
	int rv171 = 0;
	int rv172 = 0;
	int rv173 = 0;
	int rv174 = 0;
	int rv175 = 0;
	int rv176 = 0;
	int rv177 = 0;
	int rv178 = 0;
	int rv179 = 0;
	int rv180 = 0;
	int rv181 = 0;
	int rv182 = 0;
	int rv183 = 0;
	int rv184 = 0;
	int rv185 = 0;
	int rv186 = 0;
	int rv187 = 0;
	int rv188 = 0;
	int rv189 = 0;
	int rv190 = 0;
	int rv191 = 0;
	int rv192 = 0;
	int rv193 = 0;
	int rv194 = 0;
	int rv195 = 0;
	int rv196 = 0;
	int rv197 = 0;
	int rv198 = 0;
	int rv199 = 0;
	int rv200 = 0;
	int rv201 = 0;
	int rv202 = 0;
	int rv203 = 0;
	int rv204 = 0;
	int rv205 = 0;
	int rv206 = 0;
	int rv207 = 0;
	int rv208 = 0;
	int rv209 = 0;
	int rv210 = 0;
	int rv211 = 0;
	int rv212 = 0;
	int rv213 = 0;
	int rv214 = 0;
	int rv215 = 0;
	int rv216 = 0;
	int rv217 = 0;
	int rv218 = 0;
	int rv219 = 0;
	int rv220 = 0;
	int rv221 = 0;
	int rv222 = 0;
	int rv223 = 0;
	int rv224 = 0;
	int rv225 = 0;
	int rv226 = 0;
	int rv227 = 0;
	int rv228 = 0;
	int rv229 = 0;
	int rv230 = 0;
	int rv231 = 0;
	int rv232 = 0;
	int rv233 = 0;
	int rv234 = 0;
	int rv235 = 0;
	int rv236 = 0;
	int rv237 = 0;
	int rv238 = 0;
	int rv239 = 0;
	int rv240 = 0;
	int rv241 = 0;
	int rv242 = 0;
	int rv243 = 0;
	int rv244 = 0;
	int rv245 = 0;
	int rv246 = 0;
	int rv247 = 0;
	int rv248 = 0;
	int rv249 = 0;
	int rv250 = 0;
	int rv251 = 0;
	int rv252 = 0;
	int rv253 = 0;
	int rv254 = 0;
	int rv255 = 0;
	int rv256 = 0;
	int rv257 = 0;
	int rv258 = 0;
	int rv259 = 0;
	int rv260 = 0;
	int rv261 = 0;
	int rv262 = 0;
	int rv263 = 0;
	int rv264 = 0;
	int rv265 = 0;
	int rv266 = 0;
	int rv267 = 0;
	int rv268 = 0;
	int rv269 = 0;
	int rv270 = 0;
	int rv271 = 0;
	int rv272 = 0;
	int rv273 = 0;
	int rv274 = 0;
	int rv275 = 0;
	int rv276 = 0;
	int rv277 = 0;
	int rv278 = 0;
	int rv279 = 0;
	int rv280 = 0;
	int rv281 = 0;
	int rv282 = 0;
	int rv283 = 0;
	int rv284 = 0;
	int rv285 = 0;
	int rv286 = 0;
	int rv287 = 0;
	int rv288 = 0;
	int rv289 = 0;
	int rv290 = 0;
	int rv291 = 0;
	int rv292 = 0;
	int rv293 = 0;
	int rv294 = 0;
	int rv295 = 0;
	int rv296 = 0;
	int rv297 = 0;
	int rv298 = 0;
	int rv299 = 0;
	int rv300 = 0;
	int rv301 = 0;
	int rv302 = 0;
	int rv303 = 0;
	int rv304 = 0;
	int rv305 = 0;
	int rv306 = 0;
	int rv307 = 0;
	int rv308 = 0;
	int rv309 = 0;
	int rv310 = 0;
	int rv311 = 0;
	int rv312 = 0;
	int rv313 = 0;
	int rv314 = 0;
	int rv315 = 0;
	int rv316 = 0;
	int rv317 = 0;
	int rv318 = 0;
	int rv319 = 0;
	int rv320 = 0;
	int rv321 = 0;
	int rv322 = 0;
	int rv323 = 0;
	int rv324 = 0;
	int rv325 = 0;
	int rv326 = 0;
	int rv327 = 0;
	int rv328 = 0;
	int rv329 = 0;
	int rv330 = 0;
	int rv331 = 0;
	int rv332 = 0;
	int rv333 = 0;
	int rv334 = 0;
	int rv335 = 0;
	int rv336 = 0;
	int rv337 = 0;
	int rv338 = 0;
	int rv339 = 0;
	int rv340 = 0;
	int rv341 = 0;
	int rv342 = 0;
	int rv343 = 0;
	int rv344 = 0;
	int rv345 = 0;
	int rv346 = 0;
	int rv347 = 0;
	int rv348 = 0;
	int rv349 = 0;
	int rv350 = 0;
	int rv351 = 0;
	int rv352 = 0;
	int rv353 = 0;
	int rv354 = 0;
	int rv355 = 0;
	int rv356 = 0;
	int rv357 = 0;
	int rv358 = 0;
	int rv359 = 0;
	int rv360 = 0;
	int rv361 = 0;
	int rv362 = 0;
	int rv363 = 0;
	int rv364 = 0;
	int rv365 = 0;
	int rv366 = 0;
	int rv367 = 0;
	int rv368 = 0;
	int rv369 = 0;
	int rv370 = 0;
	int rv371 = 0;
	int rv372 = 0;
	int rv373 = 0;
	int rv374 = 0;
	int rv375 = 0;
	int rv376 = 0;
	int rv377 = 0;
	int rv378 = 0;
	int rv379 = 0;
	int rv380 = 0;
	int rv381 = 0;
	int rv382 = 0;
	int rv383 = 0;
	int rv384 = 0;
	int rv385 = 0;
	int rv386 = 0;
	int rv387 = 0;
	int rv388 = 0;
	int rv389 = 0;
	int rv390 = 0;
	int rv391 = 0;
	int rv392 = 0;
	int rv393 = 0;
	int rv394 = 0;
	int rv395 = 0;
	int rv396 = 0;
	int rv397 = 0;
	int rv398 = 0;
	int rv399 = 0;
	int rv400 = 0;
	int rv401 = 0;
	int rv402 = 0;
	int rv403 = 0;
	int rv404 = 0;
	int rv405 = 0;
	int rv406 = 0;
	int rv407 = 0;
	int rv408 = 0;
	int rv409 = 0;
	int rv410 = 0;
	int rv411 = 0;
	int rv412 = 0;
	int rv413 = 0;
	int rv414 = 0;
	int rv415 = 0;
	int rv416 = 0;
	int rv417 = 0;
	int rv418 = 0;
	int rv419 = 0;
	int rv420 = 0;
	int rv421 = 0;
	int rv422 = 0;
	int rv423 = 0;
	int rv424 = 0;
	int rv425 = 0;
	int rv426 = 0;
	int rv427 = 0;
	int rv428 = 0;
	int rv429 = 0;
	int rv430 = 0;
	int rv431 = 0;
	int rv432 = 0;
	int rv433 = 0;
	int rv434 = 0;
	int rv435 = 0;
	int rv436 = 0;
	int rv437 = 0;
	int rv438 = 0;
	int rv439 = 0;
	int rv440 = 0;
	int rv441 = 0;
	int rv442 = 0;
	int rv443 = 0;
	int rv444 = 0;
	int rv445 = 0;
	int rv446 = 0;
	int rv447 = 0;
	int rv448 = 0;
	int rv449 = 0;
	int rv450 = 0;
	int rv451 = 0;
	int rv452 = 0;
	int rv453 = 0;
	int rv454 = 0;
	int rv455 = 0;
	int rv456 = 0;
	int rv457 = 0;
	int rv458 = 0;
	int rv459 = 0;
	int rv460 = 0;
	int rv461 = 0;
	int rv462 = 0;
	int rv463 = 0;
	int rv464 = 0;
	int rv465 = 0;
	int rv466 = 0;
	int rv467 = 0;
	int rv468 = 0;
	int rv469 = 0;
	int rv470 = 0;
	int rv471 = 0;
	int rv472 = 0;
	int rv473 = 0;
	int rv474 = 0;
	int rv475 = 0;
	int rv476 = 0;
	int rv477 = 0;
	int rv478 = 0;
	int rv479 = 0;
	int rv480 = 0;
	int rv481 = 0;
	int rv482 = 0;
	int rv483 = 0;
	int rv484 = 0;
	int rv485 = 0;
	int rv486 = 0;
	int rv487 = 0;
	int rv488 = 0;
	int rv489 = 0;
	int rv490 = 0;
	int rv491 = 0;
	int rv492 = 0;
	int rv493 = 0;
	int rv494 = 0;
	int rv495 = 0;
	int rv496 = 0;
	int rv497 = 0;
	int rv498 = 0;
	int rv499 = 0;
	int rv500 = 0;
	int rv501 = 0;
	int rv502 = 0;
	int rv503 = 0;
	int rv504 = 0;
	int rv505 = 0;
	int rv506 = 0;
	int rv507 = 0;
	int rv508 = 0;
	int rv509 = 0;
	int rv510 = 0;
	int rv511 = 0;
	int rv512 = 0;
	int rv513 = 0;
	int rv514 = 0;
	int rv515 = 0;
	int rv516 = 0;
	int rv517 = 0;
	int rv518 = 0;
	int rv519 = 0;
	int rv520 = 0;
	int rv521 = 0;
	int rv522 = 0;
	int rv523 = 0;
	int rv524 = 0;
	int rv525 = 0;
	int rv526 = 0;
	int rv527 = 0;
	int rv528 = 0;
	int rv529 = 0;
	int rv530 = 0;
	int rv531 = 0;
	int rv532 = 0;
	int rv533 = 0;
	int rv534 = 0;
	int rv535 = 0;
	int rv536 = 0;
	int rv537 = 0;
	int rv538 = 0;
	int rv539 = 0;
	int rv540 = 0;
	int rv541 = 0;
	int rv542 = 0;
	int rv543 = 0;
	int rv544 = 0;
	int rv545 = 0;
	int rv546 = 0;
	int rv547 = 0;
	int rv548 = 0;
	int rv549 = 0;
	int rv550 = 0;
	int rv551 = 0;
	int rv552 = 0;
	int rv553 = 0;
	int rv554 = 0;
	int rv555 = 0;
	int rv556 = 0;
	int rv557 = 0;
	int rv558 = 0;
	int rv559 = 0;
	int rv560 = 0;
	int rv561 = 0;
	int rv562 = 0;
	int rv563 = 0;
	int rv564 = 0;
	int rv565 = 0;
	int rv566 = 0;
	int rv567 = 0;
	int rv568 = 0;
	int rv569 = 0;
	int rv570 = 0;
	int rv571 = 0;
	int rv572 = 0;
	int rv573 = 0;
	int rv574 = 0;
	int rv575 = 0;
	int rv576 = 0;
	int rv577 = 0;
	int rv578 = 0;
	int rv579 = 0;
	int rv580 = 0;
	int rv581 = 0;
	int rv582 = 0;
	int rv583 = 0;
	int rv584 = 0;
	int rv585 = 0;
	int rv586 = 0;
	int rv587 = 0;
	int rv588 = 0;
	int rv589 = 0;
	int rv590 = 0;
	int rv591 = 0;
	int rv592 = 0;
	int rv593 = 0;
	int rv594 = 0;
	int rv595 = 0;
	int rv596 = 0;
	int rv597 = 0;
	int rv598 = 0;
	int rv599 = 0;
	int rv600 = 0;
	int rv601 = 0;
	int rv602 = 0;
	int rv603 = 0;
	int rv604 = 0;
	int rv605 = 0;
	int rv606 = 0;
	int rv607 = 0;
	int rv608 = 0;
	int rv609 = 0;
	int rv610 = 0;
	int rv611 = 0;
	int rv612 = 0;
	int rv613 = 0;
	int rv614 = 0;
	int rv615 = 0;
	int rv616 = 0;
	int rv617 = 0;
	int rv618 = 0;
	int rv619 = 0;
	int rv620 = 0;
	int rv621 = 0;
	int rv622 = 0;
	int rv623 = 0;
	int rv624 = 0;
	int rv625 = 0;
	int rv626 = 0;
	int rv627 = 0;
	int rv628 = 0;
	int rv629 = 0;
	int rv630 = 0;
	int rv631 = 0;
	int rv632 = 0;
	int rv633 = 0;
	int rv634 = 0;
	int rv635 = 0;
	int rv636 = 0;
	int rv637 = 0;
	int rv638 = 0;
	int rv639 = 0;
	int rv640 = 0;
	int rv641 = 0;
	int rv642 = 0;
	int rv643 = 0;
	int rv644 = 0;
	int rv645 = 0;
	int rv646 = 0;
	int rv647 = 0;
	int rv648 = 0;
	int rv649 = 0;
	int rv650 = 0;
	int rv651 = 0;
	int rv652 = 0;
	int rv653 = 0;
	int rv654 = 0;
	int rv655 = 0;
	int rv656 = 0;
	int rv657 = 0;
	int rv658 = 0;
	int rv659 = 0;
	int rv660 = 0;
	int rv661 = 0;
	int rv662 = 0;
	int rv663 = 0;
	int rv664 = 0;
	int rv665 = 0;
	int rv666 = 0;
	int rv667 = 0;
	int rv668 = 0;
	int rv669 = 0;
	int rv670 = 0;
	int rv671 = 0;
	int rv672 = 0;
	int rv673 = 0;
	int rv674 = 0;
	int rv675 = 0;
	int rv676 = 0;
	int rv677 = 0;
	int rv678 = 0;
	int rv679 = 0;
	int rv680 = 0;
	int rv681 = 0;
	int rv682 = 0;
	int rv683 = 0;
	int rv684 = 0;
	int rv685 = 0;
	int rv686 = 0;
	int rv687 = 0;
	int rv688 = 0;
	int rv689 = 0;
	int rv690 = 0;
	int rv691 = 0;
	int rv692 = 0;
	int rv693 = 0;
	int rv694 = 0;
	int rv695 = 0;
	int rv696 = 0;
	int rv697 = 0;
	int rv698 = 0;
	int rv699 = 0;
	int rv700 = 0;
	int rv701 = 0;
	int rv702 = 0;
	int rv703 = 0;
	int rv704 = 0;
	int rv705 = 0;
	int rv706 = 0;
	int rv707 = 0;
	int rv708 = 0;
	int rv709 = 0;
	int rv710 = 0;
	int rv711 = 0;
	int rv712 = 0;
	int rv713 = 0;
	int rv714 = 0;
	int rv715 = 0;
	int rv716 = 0;
	int rv717 = 0;
	int rv718 = 0;
	int rv719 = 0;
	int rv720 = 0;
	int rv721 = 0;
	int rv722 = 0;
	int rv723 = 0;
	int rv724 = 0;
	int rv725 = 0;
	int rv726 = 0;
	int rv727 = 0;
	int rv728 = 0;
	int rv729 = 0;
	int rv730 = 0;
	int rv731 = 0;
	int rv732 = 0;
	int rv733 = 0;
	int rv734 = 0;
	int rv735 = 0;
	int rv736 = 0;
	int rv737 = 0;
	int rv738 = 0;
	int rv739 = 0;
	int rv740 = 0;
	int rv741 = 0;
	int rv742 = 0;
	int rv743 = 0;
	int rv744 = 0;
	int rv745 = 0;
	int rv746 = 0;
	int rv747 = 0;
	int rv748 = 0;
	int rv749 = 0;
	int rv750 = 0;
	int rv751 = 0;
	int rv752 = 0;
	int rv753 = 0;
	int rv754 = 0;
	int rv755 = 0;
	int rv756 = 0;
	int rv757 = 0;
	int rv758 = 0;
	int rv759 = 0;
	int rv760 = 0;
	int rv761 = 0;
	int rv762 = 0;
	int rv763 = 0;
	int rv764 = 0;
	int rv765 = 0;
	int rv766 = 0;
	int rv767 = 0;
	int rv768 = 0;
	int rv769 = 0;
	int rv770 = 0;
	int rv771 = 0;
	int rv772 = 0;
	int rv773 = 0;
	int rv774 = 0;
	int rv775 = 0;
	int rv776 = 0;
	int rv777 = 0;
	int rv778 = 0;
	int rv779 = 0;
	int rv780 = 0;
	int rv781 = 0;
	int rv782 = 0;
	int rv783 = 0;
	int rv784 = 0;
	int rv785 = 0;
	int rv786 = 0;
	int rv787 = 0;
	int rv788 = 0;
	int rv789 = 0;
	int rv790 = 0;
	int rv791 = 0;
	int rv792 = 0;
	int rv793 = 0;
	int rv794 = 0;
	int rv795 = 0;
	int rv796 = 0;
	int rv797 = 0;
	int rv798 = 0;
	int rv799 = 0;
	int rv800 = 0;
	int rv801 = 0;
	int rv802 = 0;
	int rv803 = 0;
	int rv804 = 0;
	int rv805 = 0;
	int rv806 = 0;
	int rv807 = 0;
	int rv808 = 0;
	int rv809 = 0;
	int rv810 = 0;
	int rv811 = 0;
	int rv812 = 0;
	int rv813 = 0;
	int rv814 = 0;
	int rv815 = 0;
	int rv816 = 0;
	int rv817 = 0;
	int rv818 = 0;
	int rv819 = 0;
	int rv820 = 0;
	int rv821 = 0;
	int rv822 = 0;
	int rv823 = 0;
	int rv824 = 0;
	int rv825 = 0;
	int rv826 = 0;
	int rv827 = 0;
	int rv828 = 0;
	int rv829 = 0;
	int rv830 = 0;
	int rv831 = 0;
	int rv832 = 0;
	int rv833 = 0;
	int rv834 = 0;
	int rv835 = 0;
	int rv836 = 0;
	int rv837 = 0;
	int rv838 = 0;
	int rv839 = 0;
	int rv840 = 0;
	int rv841 = 0;
	int rv842 = 0;
	int rv843 = 0;
	int rv844 = 0;
	int rv845 = 0;
	int rv846 = 0;
	int rv847 = 0;
	int rv848 = 0;
	int rv849 = 0;
	int rv850 = 0;
	int rv851 = 0;
	int rv852 = 0;
	int rv853 = 0;
	int rv854 = 0;
	int rv855 = 0;
	int rv856 = 0;
	int rv857 = 0;
	int rv858 = 0;
	int rv859 = 0;
	int rv860 = 0;
	int rv861 = 0;
	int rv862 = 0;
	int rv863 = 0;
	int rv864 = 0;
	int rv865 = 0;
	int rv866 = 0;
	int rv867 = 0;
	int rv868 = 0;
	int rv869 = 0;
	int rv870 = 0;
	int rv871 = 0;
	int rv872 = 0;
	int rv873 = 0;
	int rv874 = 0;
	int rv875 = 0;
	int rv876 = 0;
	int rv877 = 0;
	int rv878 = 0;
	int rv879 = 0;
	int rv880 = 0;
	int rv881 = 0;
	int rv882 = 0;
	int rv883 = 0;
	int rv884 = 0;
	int rv885 = 0;
	int rv886 = 0;
	int rv887 = 0;
	int rv888 = 0;
	int rv889 = 0;
	int rv890 = 0;
	int rv891 = 0;
	int rv892 = 0;
	int rv893 = 0;
	int rv894 = 0;
	int rv895 = 0;
	int rv896 = 0;
	int rv897 = 0;
	int rv898 = 0;
	int rv899 = 0;
	int rv900 = 0;
	int rv901 = 0;
	int rv902 = 0;
	int rv903 = 0;
	int rv904 = 0;
	int rv905 = 0;
	int rv906 = 0;
	int rv907 = 0;
	int rv908 = 0;
	int rv909 = 0;
	int rv910 = 0;
	int rv911 = 0;
	int rv912 = 0;
	int rv913 = 0;
	int rv914 = 0;
	int rv915 = 0;
	int rv916 = 0;
	int rv917 = 0;
	int rv918 = 0;
	int rv919 = 0;
	int rv920 = 0;
	int rv921 = 0;
	int rv922 = 0;
	int rv923 = 0;
	int rv924 = 0;
	int rv925 = 0;
	int rv926 = 0;
	int rv927 = 0;
	int rv928 = 0;
	int rv929 = 0;
	int rv930 = 0;
	int rv931 = 0;
	int rv932 = 0;
	int rv933 = 0;
	int rv934 = 0;
	int rv935 = 0;
	int rv936 = 0;
	int rv937 = 0;
	int rv938 = 0;
	int rv939 = 0;
	int rv940 = 0;
	int rv941 = 0;
	int rv942 = 0;
	int rv943 = 0;
	int rv944 = 0;
	int rv945 = 0;
	int rv946 = 0;
	int rv947 = 0;
	int rv948 = 0;
	int rv949 = 0;
	int rv950 = 0;
	int rv951 = 0;
	int rv952 = 0;
	int rv953 = 0;
	int rv954 = 0;
	int rv955 = 0;
	int rv956 = 0;
	int rv957 = 0;
	int rv958 = 0;
	int rv959 = 0;
	int rv960 = 0;
	int rv961 = 0;
	int rv962 = 0;
	int rv963 = 0;
	int rv964 = 0;
	int rv965 = 0;
	int rv966 = 0;
	int rv967 = 0;
	int rv968 = 0;
	int rv969 = 0;
	int rv970 = 0;
	int rv971 = 0;
	int rv972 = 0;
	int rv973 = 0;
	int rv974 = 0;
	int rv975 = 0;
	int rv976 = 0;
	int rv977 = 0;
	int rv978 = 0;
	int rv979 = 0;
	int rv980 = 0;
	int rv981 = 0;
	int rv982 = 0;
	int rv983 = 0;
	int rv984 = 0;
	int rv985 = 0;
	int rv986 = 0;
	int rv987 = 0;
	int rv988 = 0;
	int rv989 = 0;
	int rv990 = 0;
	int rv991 = 0;
	int rv992 = 0;
	int rv993 = 0;
	int rv994 = 0;
	int rv995 = 0;
	int rv996 = 0;
	int rv997 = 0;
	int rv998 = 0;
	int rv999 = 0;
	for (int i=0; i<amount; ++i) {
		// Generate two random numbers uniformly distributed between (0,1]
		double r1 = ((double)rand() / (RAND_MAX));
		double r2 = ((double)rand() / (RAND_MAX));
		
		// Calculate for standard Gaussian
		double stdGaussian = pow(-2*log(r1),0.5)*cos(2*PI*r2);
		
		// Generate random variable
		//NOTE: If randomVar is in the interval (-1,0) then a DNA string of length 0 will be generated
		double randomVar = ((double)stdDeviation*stdGaussian)+mean;
		randomVar = round(randomVar);
		
		// If negative, get the absolute value
		if (randomVar<0) abs(randomVar);

		rVarSum = rVarSum+randomVar;
		if (i==0) {
		rv0=randomVar;
		continue;
		}
		if (i==1) {
		rv1=randomVar;
		continue;
		}
		if (i==2) {
		rv2=randomVar;
		continue;
		}
		if (i==3) {
		rv3=randomVar;
		continue;
		}
		if (i==4) {
		rv4=randomVar;
		continue;
		}
		if (i==5) {
		rv5=randomVar;
		continue;
		}
		if (i==6) {
		rv6=randomVar;
		continue;
		}
		if (i==7) {
		rv7=randomVar;
		continue;
		}
		if (i==8) {
		rv8=randomVar;
		continue;
		}
		if (i==9) {
		rv9=randomVar;
		continue;
		}
		if (i==10) {
		rv10=randomVar;
		continue;
		}
		if (i==11) {
		rv11=randomVar;
		continue;
		}
		if (i==12) {
		rv12=randomVar;
		continue;
		}
		if (i==13) {
		rv13=randomVar;
		continue;
		}
		if (i==14) {
		rv14=randomVar;
		continue;
		}
		if (i==15) {
		rv15=randomVar;
		continue;
		}
		if (i==16) {
		rv16=randomVar;
		continue;
		}
		if (i==17) {
		rv17=randomVar;
		continue;
		}
		if (i==18) {
		rv18=randomVar;
		continue;
		}
		if (i==19) {
		rv19=randomVar;
		continue;
		}
		if (i==20) {
		rv20=randomVar;
		continue;
		}
		if (i==21) {
		rv21=randomVar;
		continue;
		}
		if (i==22) {
		rv22=randomVar;
		continue;
		}
		if (i==23) {
		rv23=randomVar;
		continue;
		}
		if (i==24) {
		rv24=randomVar;
		continue;
		}
		if (i==25) {
		rv25=randomVar;
		continue;
		}
		if (i==26) {
		rv26=randomVar;
		continue;
		}
		if (i==27) {
		rv27=randomVar;
		continue;
		}
		if (i==28) {
		rv28=randomVar;
		continue;
		}
		if (i==29) {
		rv29=randomVar;
		continue;
		}
		if (i==30) {
		rv30=randomVar;
		continue;
		}
		if (i==31) {
		rv31=randomVar;
		continue;
		}
		if (i==32) {
		rv32=randomVar;
		continue;
		}
		if (i==33) {
		rv33=randomVar;
		continue;
		}
		if (i==34) {
		rv34=randomVar;
		continue;
		}
		if (i==35) {
		rv35=randomVar;
		continue;
		}
		if (i==36) {
		rv36=randomVar;
		continue;
		}
		if (i==37) {
		rv37=randomVar;
		continue;
		}
		if (i==38) {
		rv38=randomVar;
		continue;
		}
		if (i==39) {
		rv39=randomVar;
		continue;
		}
		if (i==40) {
		rv40=randomVar;
		continue;
		}
		if (i==41) {
		rv41=randomVar;
		continue;
		}
		if (i==42) {
		rv42=randomVar;
		continue;
		}
		if (i==43) {
		rv43=randomVar;
		continue;
		}
		if (i==44) {
		rv44=randomVar;
		continue;
		}
		if (i==45) {
		rv45=randomVar;
		continue;
		}
		if (i==46) {
		rv46=randomVar;
		continue;
		}
		if (i==47) {
		rv47=randomVar;
		continue;
		}
		if (i==48) {
		rv48=randomVar;
		continue;
		}
		if (i==49) {
		rv49=randomVar;
		continue;
		}
		if (i==50) {
		rv50=randomVar;
		continue;
		}
		if (i==51) {
		rv51=randomVar;
		continue;
		}
		if (i==52) {
		rv52=randomVar;
		continue;
		}
		if (i==53) {
		rv53=randomVar;
		continue;
		}
		if (i==54) {
		rv54=randomVar;
		continue;
		}
		if (i==55) {
		rv55=randomVar;
		continue;
		}
		if (i==56) {
		rv56=randomVar;
		continue;
		}
		if (i==57) {
		rv57=randomVar;
		continue;
		}
		if (i==58) {
		rv58=randomVar;
		continue;
		}
		if (i==59) {
		rv59=randomVar;
		continue;
		}
		if (i==60) {
		rv60=randomVar;
		continue;
		}
		if (i==61) {
		rv61=randomVar;
		continue;
		}
		if (i==62) {
		rv62=randomVar;
		continue;
		}
		if (i==63) {
		rv63=randomVar;
		continue;
		}
		if (i==64) {
		rv64=randomVar;
		continue;
		}
		if (i==65) {
		rv65=randomVar;
		continue;
		}
		if (i==66) {
		rv66=randomVar;
		continue;
		}
		if (i==67) {
		rv67=randomVar;
		continue;
		}
		if (i==68) {
		rv68=randomVar;
		continue;
		}
		if (i==69) {
		rv69=randomVar;
		continue;
		}
		if (i==70) {
		rv70=randomVar;
		continue;
		}
		if (i==71) {
		rv71=randomVar;
		continue;
		}
		if (i==72) {
		rv72=randomVar;
		continue;
		}
		if (i==73) {
		rv73=randomVar;
		continue;
		}
		if (i==74) {
		rv74=randomVar;
		continue;
		}
		if (i==75) {
		rv75=randomVar;
		continue;
		}
		if (i==76) {
		rv76=randomVar;
		continue;
		}
		if (i==77) {
		rv77=randomVar;
		continue;
		}
		if (i==78) {
		rv78=randomVar;
		continue;
		}
		if (i==79) {
		rv79=randomVar;
		continue;
		}
		if (i==80) {
		rv80=randomVar;
		continue;
		}
		if (i==81) {
		rv81=randomVar;
		continue;
		}
		if (i==82) {
		rv82=randomVar;
		continue;
		}
		if (i==83) {
		rv83=randomVar;
		continue;
		}
		if (i==84) {
		rv84=randomVar;
		continue;
		}
		if (i==85) {
		rv85=randomVar;
		continue;
		}
		if (i==86) {
		rv86=randomVar;
		continue;
		}
		if (i==87) {
		rv87=randomVar;
		continue;
		}
		if (i==88) {
		rv88=randomVar;
		continue;
		}
		if (i==89) {
		rv89=randomVar;
		continue;
		}
		if (i==90) {
		rv90=randomVar;
		continue;
		}
		if (i==91) {
		rv91=randomVar;
		continue;
		}
		if (i==92) {
		rv92=randomVar;
		continue;
		}
		if (i==93) {
		rv93=randomVar;
		continue;
		}
		if (i==94) {
		rv94=randomVar;
		continue;
		}
		if (i==95) {
		rv95=randomVar;
		continue;
		}
		if (i==96) {
		rv96=randomVar;
		continue;
		}
		if (i==97) {
		rv97=randomVar;
		continue;
		}
		if (i==98) {
		rv98=randomVar;
		continue;
		}
		if (i==99) {
		rv99=randomVar;
		continue;
		}
		if (i==100) {
		rv100=randomVar;
		continue;
		}
		if (i==101) {
		rv101=randomVar;
		continue;
		}
		if (i==102) {
		rv102=randomVar;
		continue;
		}
		if (i==103) {
		rv103=randomVar;
		continue;
		}
		if (i==104) {
		rv104=randomVar;
		continue;
		}
		if (i==105) {
		rv105=randomVar;
		continue;
		}
		if (i==106) {
		rv106=randomVar;
		continue;
		}
		if (i==107) {
		rv107=randomVar;
		continue;
		}
		if (i==108) {
		rv108=randomVar;
		continue;
		}
		if (i==109) {
		rv109=randomVar;
		continue;
		}
		if (i==110) {
		rv110=randomVar;
		continue;
		}
		if (i==111) {
		rv111=randomVar;
		continue;
		}
		if (i==112) {
		rv112=randomVar;
		continue;
		}
		if (i==113) {
		rv113=randomVar;
		continue;
		}
		if (i==114) {
		rv114=randomVar;
		continue;
		}
		if (i==115) {
		rv115=randomVar;
		continue;
		}
		if (i==116) {
		rv116=randomVar;
		continue;
		}
		if (i==117) {
		rv117=randomVar;
		continue;
		}
		if (i==118) {
		rv118=randomVar;
		continue;
		}
		if (i==119) {
		rv119=randomVar;
		continue;
		}
		if (i==120) {
		rv120=randomVar;
		continue;
		}
		if (i==121) {
		rv121=randomVar;
		continue;
		}
		if (i==122) {
		rv122=randomVar;
		continue;
		}
		if (i==123) {
		rv123=randomVar;
		continue;
		}
		if (i==124) {
		rv124=randomVar;
		continue;
		}
		if (i==125) {
		rv125=randomVar;
		continue;
		}
		if (i==126) {
		rv126=randomVar;
		continue;
		}
		if (i==127) {
		rv127=randomVar;
		continue;
		}
		if (i==128) {
		rv128=randomVar;
		continue;
		}
		if (i==129) {
		rv129=randomVar;
		continue;
		}
		if (i==130) {
		rv130=randomVar;
		continue;
		}
		if (i==131) {
		rv131=randomVar;
		continue;
		}
		if (i==132) {
		rv132=randomVar;
		continue;
		}
		if (i==133) {
		rv133=randomVar;
		continue;
		}
		if (i==134) {
		rv134=randomVar;
		continue;
		}
		if (i==135) {
		rv135=randomVar;
		continue;
		}
		if (i==136) {
		rv136=randomVar;
		continue;
		}
		if (i==137) {
		rv137=randomVar;
		continue;
		}
		if (i==138) {
		rv138=randomVar;
		continue;
		}
		if (i==139) {
		rv139=randomVar;
		continue;
		}
		if (i==140) {
		rv140=randomVar;
		continue;
		}
		if (i==141) {
		rv141=randomVar;
		continue;
		}
		if (i==142) {
		rv142=randomVar;
		continue;
		}
		if (i==143) {
		rv143=randomVar;
		continue;
		}
		if (i==144) {
		rv144=randomVar;
		continue;
		}
		if (i==145) {
		rv145=randomVar;
		continue;
		}
		if (i==146) {
		rv146=randomVar;
		continue;
		}
		if (i==147) {
		rv147=randomVar;
		continue;
		}
		if (i==148) {
		rv148=randomVar;
		continue;
		}
		if (i==149) {
		rv149=randomVar;
		continue;
		}
		if (i==150) {
		rv150=randomVar;
		continue;
		}
		if (i==151) {
		rv151=randomVar;
		continue;
		}
		if (i==152) {
		rv152=randomVar;
		continue;
		}
		if (i==153) {
		rv153=randomVar;
		continue;
		}
		if (i==154) {
		rv154=randomVar;
		continue;
		}
		if (i==155) {
		rv155=randomVar;
		continue;
		}
		if (i==156) {
		rv156=randomVar;
		continue;
		}
		if (i==157) {
		rv157=randomVar;
		continue;
		}
		if (i==158) {
		rv158=randomVar;
		continue;
		}
		if (i==159) {
		rv159=randomVar;
		continue;
		}
		if (i==160) {
		rv160=randomVar;
		continue;
		}
		if (i==161) {
		rv161=randomVar;
		continue;
		}
		if (i==162) {
		rv162=randomVar;
		continue;
		}
		if (i==163) {
		rv163=randomVar;
		continue;
		}
		if (i==164) {
		rv164=randomVar;
		continue;
		}
		if (i==165) {
		rv165=randomVar;
		continue;
		}
		if (i==166) {
		rv166=randomVar;
		continue;
		}
		if (i==167) {
		rv167=randomVar;
		continue;
		}
		if (i==168) {
		rv168=randomVar;
		continue;
		}
		if (i==169) {
		rv169=randomVar;
		continue;
		}
		if (i==170) {
		rv170=randomVar;
		continue;
		}
		if (i==171) {
		rv171=randomVar;
		continue;
		}
		if (i==172) {
		rv172=randomVar;
		continue;
		}
		if (i==173) {
		rv173=randomVar;
		continue;
		}
		if (i==174) {
		rv174=randomVar;
		continue;
		}
		if (i==175) {
		rv175=randomVar;
		continue;
		}
		if (i==176) {
		rv176=randomVar;
		continue;
		}
		if (i==177) {
		rv177=randomVar;
		continue;
		}
		if (i==178) {
		rv178=randomVar;
		continue;
		}
		if (i==179) {
		rv179=randomVar;
		continue;
		}
		if (i==180) {
		rv180=randomVar;
		continue;
		}
		if (i==181) {
		rv181=randomVar;
		continue;
		}
		if (i==182) {
		rv182=randomVar;
		continue;
		}
		if (i==183) {
		rv183=randomVar;
		continue;
		}
		if (i==184) {
		rv184=randomVar;
		continue;
		}
		if (i==185) {
		rv185=randomVar;
		continue;
		}
		if (i==186) {
		rv186=randomVar;
		continue;
		}
		if (i==187) {
		rv187=randomVar;
		continue;
		}
		if (i==188) {
		rv188=randomVar;
		continue;
		}
		if (i==189) {
		rv189=randomVar;
		continue;
		}
		if (i==190) {
		rv190=randomVar;
		continue;
		}
		if (i==191) {
		rv191=randomVar;
		continue;
		}
		if (i==192) {
		rv192=randomVar;
		continue;
		}
		if (i==193) {
		rv193=randomVar;
		continue;
		}
		if (i==194) {
		rv194=randomVar;
		continue;
		}
		if (i==195) {
		rv195=randomVar;
		continue;
		}
		if (i==196) {
		rv196=randomVar;
		continue;
		}
		if (i==197) {
		rv197=randomVar;
		continue;
		}
		if (i==198) {
		rv198=randomVar;
		continue;
		}
		if (i==199) {
		rv199=randomVar;
		continue;
		}
		if (i==200) {
		rv200=randomVar;
		continue;
		}
		if (i==201) {
		rv201=randomVar;
		continue;
		}
		if (i==202) {
		rv202=randomVar;
		continue;
		}
		if (i==203) {
		rv203=randomVar;
		continue;
		}
		if (i==204) {
		rv204=randomVar;
		continue;
		}
		if (i==205) {
		rv205=randomVar;
		continue;
		}
		if (i==206) {
		rv206=randomVar;
		continue;
		}
		if (i==207) {
		rv207=randomVar;
		continue;
		}
		if (i==208) {
		rv208=randomVar;
		continue;
		}
		if (i==209) {
		rv209=randomVar;
		continue;
		}
		if (i==210) {
		rv210=randomVar;
		continue;
		}
		if (i==211) {
		rv211=randomVar;
		continue;
		}
		if (i==212) {
		rv212=randomVar;
		continue;
		}
		if (i==213) {
		rv213=randomVar;
		continue;
		}
		if (i==214) {
		rv214=randomVar;
		continue;
		}
		if (i==215) {
		rv215=randomVar;
		continue;
		}
		if (i==216) {
		rv216=randomVar;
		continue;
		}
		if (i==217) {
		rv217=randomVar;
		continue;
		}
		if (i==218) {
		rv218=randomVar;
		continue;
		}
		if (i==219) {
		rv219=randomVar;
		continue;
		}
		if (i==220) {
		rv220=randomVar;
		continue;
		}
		if (i==221) {
		rv221=randomVar;
		continue;
		}
		if (i==222) {
		rv222=randomVar;
		continue;
		}
		if (i==223) {
		rv223=randomVar;
		continue;
		}
		if (i==224) {
		rv224=randomVar;
		continue;
		}
		if (i==225) {
		rv225=randomVar;
		continue;
		}
		if (i==226) {
		rv226=randomVar;
		continue;
		}
		if (i==227) {
		rv227=randomVar;
		continue;
		}
		if (i==228) {
		rv228=randomVar;
		continue;
		}
		if (i==229) {
		rv229=randomVar;
		continue;
		}
		if (i==230) {
		rv230=randomVar;
		continue;
		}
		if (i==231) {
		rv231=randomVar;
		continue;
		}
		if (i==232) {
		rv232=randomVar;
		continue;
		}
		if (i==233) {
		rv233=randomVar;
		continue;
		}
		if (i==234) {
		rv234=randomVar;
		continue;
		}
		if (i==235) {
		rv235=randomVar;
		continue;
		}
		if (i==236) {
		rv236=randomVar;
		continue;
		}
		if (i==237) {
		rv237=randomVar;
		continue;
		}
		if (i==238) {
		rv238=randomVar;
		continue;
		}
		if (i==239) {
		rv239=randomVar;
		continue;
		}
		if (i==240) {
		rv240=randomVar;
		continue;
		}
		if (i==241) {
		rv241=randomVar;
		continue;
		}
		if (i==242) {
		rv242=randomVar;
		continue;
		}
		if (i==243) {
		rv243=randomVar;
		continue;
		}
		if (i==244) {
		rv244=randomVar;
		continue;
		}
		if (i==245) {
		rv245=randomVar;
		continue;
		}
		if (i==246) {
		rv246=randomVar;
		continue;
		}
		if (i==247) {
		rv247=randomVar;
		continue;
		}
		if (i==248) {
		rv248=randomVar;
		continue;
		}
		if (i==249) {
		rv249=randomVar;
		continue;
		}
		if (i==250) {
		rv250=randomVar;
		continue;
		}
		if (i==251) {
		rv251=randomVar;
		continue;
		}
		if (i==252) {
		rv252=randomVar;
		continue;
		}
		if (i==253) {
		rv253=randomVar;
		continue;
		}
		if (i==254) {
		rv254=randomVar;
		continue;
		}
		if (i==255) {
		rv255=randomVar;
		continue;
		}
		if (i==256) {
		rv256=randomVar;
		continue;
		}
		if (i==257) {
		rv257=randomVar;
		continue;
		}
		if (i==258) {
		rv258=randomVar;
		continue;
		}
		if (i==259) {
		rv259=randomVar;
		continue;
		}
		if (i==260) {
		rv260=randomVar;
		continue;
		}
		if (i==261) {
		rv261=randomVar;
		continue;
		}
		if (i==262) {
		rv262=randomVar;
		continue;
		}
		if (i==263) {
		rv263=randomVar;
		continue;
		}
		if (i==264) {
		rv264=randomVar;
		continue;
		}
		if (i==265) {
		rv265=randomVar;
		continue;
		}
		if (i==266) {
		rv266=randomVar;
		continue;
		}
		if (i==267) {
		rv267=randomVar;
		continue;
		}
		if (i==268) {
		rv268=randomVar;
		continue;
		}
		if (i==269) {
		rv269=randomVar;
		continue;
		}
		if (i==270) {
		rv270=randomVar;
		continue;
		}
		if (i==271) {
		rv271=randomVar;
		continue;
		}
		if (i==272) {
		rv272=randomVar;
		continue;
		}
		if (i==273) {
		rv273=randomVar;
		continue;
		}
		if (i==274) {
		rv274=randomVar;
		continue;
		}
		if (i==275) {
		rv275=randomVar;
		continue;
		}
		if (i==276) {
		rv276=randomVar;
		continue;
		}
		if (i==277) {
		rv277=randomVar;
		continue;
		}
		if (i==278) {
		rv278=randomVar;
		continue;
		}
		if (i==279) {
		rv279=randomVar;
		continue;
		}
		if (i==280) {
		rv280=randomVar;
		continue;
		}
		if (i==281) {
		rv281=randomVar;
		continue;
		}
		if (i==282) {
		rv282=randomVar;
		continue;
		}
		if (i==283) {
		rv283=randomVar;
		continue;
		}
		if (i==284) {
		rv284=randomVar;
		continue;
		}
		if (i==285) {
		rv285=randomVar;
		continue;
		}
		if (i==286) {
		rv286=randomVar;
		continue;
		}
		if (i==287) {
		rv287=randomVar;
		continue;
		}
		if (i==288) {
		rv288=randomVar;
		continue;
		}
		if (i==289) {
		rv289=randomVar;
		continue;
		}
		if (i==290) {
		rv290=randomVar;
		continue;
		}
		if (i==291) {
		rv291=randomVar;
		continue;
		}
		if (i==292) {
		rv292=randomVar;
		continue;
		}
		if (i==293) {
		rv293=randomVar;
		continue;
		}
		if (i==294) {
		rv294=randomVar;
		continue;
		}
		if (i==295) {
		rv295=randomVar;
		continue;
		}
		if (i==296) {
		rv296=randomVar;
		continue;
		}
		if (i==297) {
		rv297=randomVar;
		continue;
		}
		if (i==298) {
		rv298=randomVar;
		continue;
		}
		if (i==299) {
		rv299=randomVar;
		continue;
		}
		if (i==300) {
		rv300=randomVar;
		continue;
		}
		if (i==301) {
		rv301=randomVar;
		continue;
		}
		if (i==302) {
		rv302=randomVar;
		continue;
		}
		if (i==303) {
		rv303=randomVar;
		continue;
		}
		if (i==304) {
		rv304=randomVar;
		continue;
		}
		if (i==305) {
		rv305=randomVar;
		continue;
		}
		if (i==306) {
		rv306=randomVar;
		continue;
		}
		if (i==307) {
		rv307=randomVar;
		continue;
		}
		if (i==308) {
		rv308=randomVar;
		continue;
		}
		if (i==309) {
		rv309=randomVar;
		continue;
		}
		if (i==310) {
		rv310=randomVar;
		continue;
		}
		if (i==311) {
		rv311=randomVar;
		continue;
		}
		if (i==312) {
		rv312=randomVar;
		continue;
		}
		if (i==313) {
		rv313=randomVar;
		continue;
		}
		if (i==314) {
		rv314=randomVar;
		continue;
		}
		if (i==315) {
		rv315=randomVar;
		continue;
		}
		if (i==316) {
		rv316=randomVar;
		continue;
		}
		if (i==317) {
		rv317=randomVar;
		continue;
		}
		if (i==318) {
		rv318=randomVar;
		continue;
		}
		if (i==319) {
		rv319=randomVar;
		continue;
		}
		if (i==320) {
		rv320=randomVar;
		continue;
		}
		if (i==321) {
		rv321=randomVar;
		continue;
		}
		if (i==322) {
		rv322=randomVar;
		continue;
		}
		if (i==323) {
		rv323=randomVar;
		continue;
		}
		if (i==324) {
		rv324=randomVar;
		continue;
		}
		if (i==325) {
		rv325=randomVar;
		continue;
		}
		if (i==326) {
		rv326=randomVar;
		continue;
		}
		if (i==327) {
		rv327=randomVar;
		continue;
		}
		if (i==328) {
		rv328=randomVar;
		continue;
		}
		if (i==329) {
		rv329=randomVar;
		continue;
		}
		if (i==330) {
		rv330=randomVar;
		continue;
		}
		if (i==331) {
		rv331=randomVar;
		continue;
		}
		if (i==332) {
		rv332=randomVar;
		continue;
		}
		if (i==333) {
		rv333=randomVar;
		continue;
		}
		if (i==334) {
		rv334=randomVar;
		continue;
		}
		if (i==335) {
		rv335=randomVar;
		continue;
		}
		if (i==336) {
		rv336=randomVar;
		continue;
		}
		if (i==337) {
		rv337=randomVar;
		continue;
		}
		if (i==338) {
		rv338=randomVar;
		continue;
		}
		if (i==339) {
		rv339=randomVar;
		continue;
		}
		if (i==340) {
		rv340=randomVar;
		continue;
		}
		if (i==341) {
		rv341=randomVar;
		continue;
		}
		if (i==342) {
		rv342=randomVar;
		continue;
		}
		if (i==343) {
		rv343=randomVar;
		continue;
		}
		if (i==344) {
		rv344=randomVar;
		continue;
		}
		if (i==345) {
		rv345=randomVar;
		continue;
		}
		if (i==346) {
		rv346=randomVar;
		continue;
		}
		if (i==347) {
		rv347=randomVar;
		continue;
		}
		if (i==348) {
		rv348=randomVar;
		continue;
		}
		if (i==349) {
		rv349=randomVar;
		continue;
		}
		if (i==350) {
		rv350=randomVar;
		continue;
		}
		if (i==351) {
		rv351=randomVar;
		continue;
		}
		if (i==352) {
		rv352=randomVar;
		continue;
		}
		if (i==353) {
		rv353=randomVar;
		continue;
		}
		if (i==354) {
		rv354=randomVar;
		continue;
		}
		if (i==355) {
		rv355=randomVar;
		continue;
		}
		if (i==356) {
		rv356=randomVar;
		continue;
		}
		if (i==357) {
		rv357=randomVar;
		continue;
		}
		if (i==358) {
		rv358=randomVar;
		continue;
		}
		if (i==359) {
		rv359=randomVar;
		continue;
		}
		if (i==360) {
		rv360=randomVar;
		continue;
		}
		if (i==361) {
		rv361=randomVar;
		continue;
		}
		if (i==362) {
		rv362=randomVar;
		continue;
		}
		if (i==363) {
		rv363=randomVar;
		continue;
		}
		if (i==364) {
		rv364=randomVar;
		continue;
		}
		if (i==365) {
		rv365=randomVar;
		continue;
		}
		if (i==366) {
		rv366=randomVar;
		continue;
		}
		if (i==367) {
		rv367=randomVar;
		continue;
		}
		if (i==368) {
		rv368=randomVar;
		continue;
		}
		if (i==369) {
		rv369=randomVar;
		continue;
		}
		if (i==370) {
		rv370=randomVar;
		continue;
		}
		if (i==371) {
		rv371=randomVar;
		continue;
		}
		if (i==372) {
		rv372=randomVar;
		continue;
		}
		if (i==373) {
		rv373=randomVar;
		continue;
		}
		if (i==374) {
		rv374=randomVar;
		continue;
		}
		if (i==375) {
		rv375=randomVar;
		continue;
		}
		if (i==376) {
		rv376=randomVar;
		continue;
		}
		if (i==377) {
		rv377=randomVar;
		continue;
		}
		if (i==378) {
		rv378=randomVar;
		continue;
		}
		if (i==379) {
		rv379=randomVar;
		continue;
		}
		if (i==380) {
		rv380=randomVar;
		continue;
		}
		if (i==381) {
		rv381=randomVar;
		continue;
		}
		if (i==382) {
		rv382=randomVar;
		continue;
		}
		if (i==383) {
		rv383=randomVar;
		continue;
		}
		if (i==384) {
		rv384=randomVar;
		continue;
		}
		if (i==385) {
		rv385=randomVar;
		continue;
		}
		if (i==386) {
		rv386=randomVar;
		continue;
		}
		if (i==387) {
		rv387=randomVar;
		continue;
		}
		if (i==388) {
		rv388=randomVar;
		continue;
		}
		if (i==389) {
		rv389=randomVar;
		continue;
		}
		if (i==390) {
		rv390=randomVar;
		continue;
		}
		if (i==391) {
		rv391=randomVar;
		continue;
		}
		if (i==392) {
		rv392=randomVar;
		continue;
		}
		if (i==393) {
		rv393=randomVar;
		continue;
		}
		if (i==394) {
		rv394=randomVar;
		continue;
		}
		if (i==395) {
		rv395=randomVar;
		continue;
		}
		if (i==396) {
		rv396=randomVar;
		continue;
		}
		if (i==397) {
		rv397=randomVar;
		continue;
		}
		if (i==398) {
		rv398=randomVar;
		continue;
		}
		if (i==399) {
		rv399=randomVar;
		continue;
		}
		if (i==400) {
		rv400=randomVar;
		continue;
		}
		if (i==401) {
		rv401=randomVar;
		continue;
		}
		if (i==402) {
		rv402=randomVar;
		continue;
		}
		if (i==403) {
		rv403=randomVar;
		continue;
		}
		if (i==404) {
		rv404=randomVar;
		continue;
		}
		if (i==405) {
		rv405=randomVar;
		continue;
		}
		if (i==406) {
		rv406=randomVar;
		continue;
		}
		if (i==407) {
		rv407=randomVar;
		continue;
		}
		if (i==408) {
		rv408=randomVar;
		continue;
		}
		if (i==409) {
		rv409=randomVar;
		continue;
		}
		if (i==410) {
		rv410=randomVar;
		continue;
		}
		if (i==411) {
		rv411=randomVar;
		continue;
		}
		if (i==412) {
		rv412=randomVar;
		continue;
		}
		if (i==413) {
		rv413=randomVar;
		continue;
		}
		if (i==414) {
		rv414=randomVar;
		continue;
		}
		if (i==415) {
		rv415=randomVar;
		continue;
		}
		if (i==416) {
		rv416=randomVar;
		continue;
		}
		if (i==417) {
		rv417=randomVar;
		continue;
		}
		if (i==418) {
		rv418=randomVar;
		continue;
		}
		if (i==419) {
		rv419=randomVar;
		continue;
		}
		if (i==420) {
		rv420=randomVar;
		continue;
		}
		if (i==421) {
		rv421=randomVar;
		continue;
		}
		if (i==422) {
		rv422=randomVar;
		continue;
		}
		if (i==423) {
		rv423=randomVar;
		continue;
		}
		if (i==424) {
		rv424=randomVar;
		continue;
		}
		if (i==425) {
		rv425=randomVar;
		continue;
		}
		if (i==426) {
		rv426=randomVar;
		continue;
		}
		if (i==427) {
		rv427=randomVar;
		continue;
		}
		if (i==428) {
		rv428=randomVar;
		continue;
		}
		if (i==429) {
		rv429=randomVar;
		continue;
		}
		if (i==430) {
		rv430=randomVar;
		continue;
		}
		if (i==431) {
		rv431=randomVar;
		continue;
		}
		if (i==432) {
		rv432=randomVar;
		continue;
		}
		if (i==433) {
		rv433=randomVar;
		continue;
		}
		if (i==434) {
		rv434=randomVar;
		continue;
		}
		if (i==435) {
		rv435=randomVar;
		continue;
		}
		if (i==436) {
		rv436=randomVar;
		continue;
		}
		if (i==437) {
		rv437=randomVar;
		continue;
		}
		if (i==438) {
		rv438=randomVar;
		continue;
		}
		if (i==439) {
		rv439=randomVar;
		continue;
		}
		if (i==440) {
		rv440=randomVar;
		continue;
		}
		if (i==441) {
		rv441=randomVar;
		continue;
		}
		if (i==442) {
		rv442=randomVar;
		continue;
		}
		if (i==443) {
		rv443=randomVar;
		continue;
		}
		if (i==444) {
		rv444=randomVar;
		continue;
		}
		if (i==445) {
		rv445=randomVar;
		continue;
		}
		if (i==446) {
		rv446=randomVar;
		continue;
		}
		if (i==447) {
		rv447=randomVar;
		continue;
		}
		if (i==448) {
		rv448=randomVar;
		continue;
		}
		if (i==449) {
		rv449=randomVar;
		continue;
		}
		if (i==450) {
		rv450=randomVar;
		continue;
		}
		if (i==451) {
		rv451=randomVar;
		continue;
		}
		if (i==452) {
		rv452=randomVar;
		continue;
		}
		if (i==453) {
		rv453=randomVar;
		continue;
		}
		if (i==454) {
		rv454=randomVar;
		continue;
		}
		if (i==455) {
		rv455=randomVar;
		continue;
		}
		if (i==456) {
		rv456=randomVar;
		continue;
		}
		if (i==457) {
		rv457=randomVar;
		continue;
		}
		if (i==458) {
		rv458=randomVar;
		continue;
		}
		if (i==459) {
		rv459=randomVar;
		continue;
		}
		if (i==460) {
		rv460=randomVar;
		continue;
		}
		if (i==461) {
		rv461=randomVar;
		continue;
		}
		if (i==462) {
		rv462=randomVar;
		continue;
		}
		if (i==463) {
		rv463=randomVar;
		continue;
		}
		if (i==464) {
		rv464=randomVar;
		continue;
		}
		if (i==465) {
		rv465=randomVar;
		continue;
		}
		if (i==466) {
		rv466=randomVar;
		continue;
		}
		if (i==467) {
		rv467=randomVar;
		continue;
		}
		if (i==468) {
		rv468=randomVar;
		continue;
		}
		if (i==469) {
		rv469=randomVar;
		continue;
		}
		if (i==470) {
		rv470=randomVar;
		continue;
		}
		if (i==471) {
		rv471=randomVar;
		continue;
		}
		if (i==472) {
		rv472=randomVar;
		continue;
		}
		if (i==473) {
		rv473=randomVar;
		continue;
		}
		if (i==474) {
		rv474=randomVar;
		continue;
		}
		if (i==475) {
		rv475=randomVar;
		continue;
		}
		if (i==476) {
		rv476=randomVar;
		continue;
		}
		if (i==477) {
		rv477=randomVar;
		continue;
		}
		if (i==478) {
		rv478=randomVar;
		continue;
		}
		if (i==479) {
		rv479=randomVar;
		continue;
		}
		if (i==480) {
		rv480=randomVar;
		continue;
		}
		if (i==481) {
		rv481=randomVar;
		continue;
		}
		if (i==482) {
		rv482=randomVar;
		continue;
		}
		if (i==483) {
		rv483=randomVar;
		continue;
		}
		if (i==484) {
		rv484=randomVar;
		continue;
		}
		if (i==485) {
		rv485=randomVar;
		continue;
		}
		if (i==486) {
		rv486=randomVar;
		continue;
		}
		if (i==487) {
		rv487=randomVar;
		continue;
		}
		if (i==488) {
		rv488=randomVar;
		continue;
		}
		if (i==489) {
		rv489=randomVar;
		continue;
		}
		if (i==490) {
		rv490=randomVar;
		continue;
		}
		if (i==491) {
		rv491=randomVar;
		continue;
		}
		if (i==492) {
		rv492=randomVar;
		continue;
		}
		if (i==493) {
		rv493=randomVar;
		continue;
		}
		if (i==494) {
		rv494=randomVar;
		continue;
		}
		if (i==495) {
		rv495=randomVar;
		continue;
		}
		if (i==496) {
		rv496=randomVar;
		continue;
		}
		if (i==497) {
		rv497=randomVar;
		continue;
		}
		if (i==498) {
		rv498=randomVar;
		continue;
		}
		if (i==499) {
		rv499=randomVar;
		continue;
		}
		if (i==500) {
		rv500=randomVar;
		continue;
		}
		if (i==501) {
		rv501=randomVar;
		continue;
		}
		if (i==502) {
		rv502=randomVar;
		continue;
		}
		if (i==503) {
		rv503=randomVar;
		continue;
		}
		if (i==504) {
		rv504=randomVar;
		continue;
		}
		if (i==505) {
		rv505=randomVar;
		continue;
		}
		if (i==506) {
		rv506=randomVar;
		continue;
		}
		if (i==507) {
		rv507=randomVar;
		continue;
		}
		if (i==508) {
		rv508=randomVar;
		continue;
		}
		if (i==509) {
		rv509=randomVar;
		continue;
		}
		if (i==510) {
		rv510=randomVar;
		continue;
		}
		if (i==511) {
		rv511=randomVar;
		continue;
		}
		if (i==512) {
		rv512=randomVar;
		continue;
		}
		if (i==513) {
		rv513=randomVar;
		continue;
		}
		if (i==514) {
		rv514=randomVar;
		continue;
		}
		if (i==515) {
		rv515=randomVar;
		continue;
		}
		if (i==516) {
		rv516=randomVar;
		continue;
		}
		if (i==517) {
		rv517=randomVar;
		continue;
		}
		if (i==518) {
		rv518=randomVar;
		continue;
		}
		if (i==519) {
		rv519=randomVar;
		continue;
		}
		if (i==520) {
		rv520=randomVar;
		continue;
		}
		if (i==521) {
		rv521=randomVar;
		continue;
		}
		if (i==522) {
		rv522=randomVar;
		continue;
		}
		if (i==523) {
		rv523=randomVar;
		continue;
		}
		if (i==524) {
		rv524=randomVar;
		continue;
		}
		if (i==525) {
		rv525=randomVar;
		continue;
		}
		if (i==526) {
		rv526=randomVar;
		continue;
		}
		if (i==527) {
		rv527=randomVar;
		continue;
		}
		if (i==528) {
		rv528=randomVar;
		continue;
		}
		if (i==529) {
		rv529=randomVar;
		continue;
		}
		if (i==530) {
		rv530=randomVar;
		continue;
		}
		if (i==531) {
		rv531=randomVar;
		continue;
		}
		if (i==532) {
		rv532=randomVar;
		continue;
		}
		if (i==533) {
		rv533=randomVar;
		continue;
		}
		if (i==534) {
		rv534=randomVar;
		continue;
		}
		if (i==535) {
		rv535=randomVar;
		continue;
		}
		if (i==536) {
		rv536=randomVar;
		continue;
		}
		if (i==537) {
		rv537=randomVar;
		continue;
		}
		if (i==538) {
		rv538=randomVar;
		continue;
		}
		if (i==539) {
		rv539=randomVar;
		continue;
		}
		if (i==540) {
		rv540=randomVar;
		continue;
		}
		if (i==541) {
		rv541=randomVar;
		continue;
		}
		if (i==542) {
		rv542=randomVar;
		continue;
		}
		if (i==543) {
		rv543=randomVar;
		continue;
		}
		if (i==544) {
		rv544=randomVar;
		continue;
		}
		if (i==545) {
		rv545=randomVar;
		continue;
		}
		if (i==546) {
		rv546=randomVar;
		continue;
		}
		if (i==547) {
		rv547=randomVar;
		continue;
		}
		if (i==548) {
		rv548=randomVar;
		continue;
		}
		if (i==549) {
		rv549=randomVar;
		continue;
		}
		if (i==550) {
		rv550=randomVar;
		continue;
		}
		if (i==551) {
		rv551=randomVar;
		continue;
		}
		if (i==552) {
		rv552=randomVar;
		continue;
		}
		if (i==553) {
		rv553=randomVar;
		continue;
		}
		if (i==554) {
		rv554=randomVar;
		continue;
		}
		if (i==555) {
		rv555=randomVar;
		continue;
		}
		if (i==556) {
		rv556=randomVar;
		continue;
		}
		if (i==557) {
		rv557=randomVar;
		continue;
		}
		if (i==558) {
		rv558=randomVar;
		continue;
		}
		if (i==559) {
		rv559=randomVar;
		continue;
		}
		if (i==560) {
		rv560=randomVar;
		continue;
		}
		if (i==561) {
		rv561=randomVar;
		continue;
		}
		if (i==562) {
		rv562=randomVar;
		continue;
		}
		if (i==563) {
		rv563=randomVar;
		continue;
		}
		if (i==564) {
		rv564=randomVar;
		continue;
		}
		if (i==565) {
		rv565=randomVar;
		continue;
		}
		if (i==566) {
		rv566=randomVar;
		continue;
		}
		if (i==567) {
		rv567=randomVar;
		continue;
		}
		if (i==568) {
		rv568=randomVar;
		continue;
		}
		if (i==569) {
		rv569=randomVar;
		continue;
		}
		if (i==570) {
		rv570=randomVar;
		continue;
		}
		if (i==571) {
		rv571=randomVar;
		continue;
		}
		if (i==572) {
		rv572=randomVar;
		continue;
		}
		if (i==573) {
		rv573=randomVar;
		continue;
		}
		if (i==574) {
		rv574=randomVar;
		continue;
		}
		if (i==575) {
		rv575=randomVar;
		continue;
		}
		if (i==576) {
		rv576=randomVar;
		continue;
		}
		if (i==577) {
		rv577=randomVar;
		continue;
		}
		if (i==578) {
		rv578=randomVar;
		continue;
		}
		if (i==579) {
		rv579=randomVar;
		continue;
		}
		if (i==580) {
		rv580=randomVar;
		continue;
		}
		if (i==581) {
		rv581=randomVar;
		continue;
		}
		if (i==582) {
		rv582=randomVar;
		continue;
		}
		if (i==583) {
		rv583=randomVar;
		continue;
		}
		if (i==584) {
		rv584=randomVar;
		continue;
		}
		if (i==585) {
		rv585=randomVar;
		continue;
		}
		if (i==586) {
		rv586=randomVar;
		continue;
		}
		if (i==587) {
		rv587=randomVar;
		continue;
		}
		if (i==588) {
		rv588=randomVar;
		continue;
		}
		if (i==589) {
		rv589=randomVar;
		continue;
		}
		if (i==590) {
		rv590=randomVar;
		continue;
		}
		if (i==591) {
		rv591=randomVar;
		continue;
		}
		if (i==592) {
		rv592=randomVar;
		continue;
		}
		if (i==593) {
		rv593=randomVar;
		continue;
		}
		if (i==594) {
		rv594=randomVar;
		continue;
		}
		if (i==595) {
		rv595=randomVar;
		continue;
		}
		if (i==596) {
		rv596=randomVar;
		continue;
		}
		if (i==597) {
		rv597=randomVar;
		continue;
		}
		if (i==598) {
		rv598=randomVar;
		continue;
		}
		if (i==599) {
		rv599=randomVar;
		continue;
		}
		if (i==600) {
		rv600=randomVar;
		continue;
		}
		if (i==601) {
		rv601=randomVar;
		continue;
		}
		if (i==602) {
		rv602=randomVar;
		continue;
		}
		if (i==603) {
		rv603=randomVar;
		continue;
		}
		if (i==604) {
		rv604=randomVar;
		continue;
		}
		if (i==605) {
		rv605=randomVar;
		continue;
		}
		if (i==606) {
		rv606=randomVar;
		continue;
		}
		if (i==607) {
		rv607=randomVar;
		continue;
		}
		if (i==608) {
		rv608=randomVar;
		continue;
		}
		if (i==609) {
		rv609=randomVar;
		continue;
		}
		if (i==610) {
		rv610=randomVar;
		continue;
		}
		if (i==611) {
		rv611=randomVar;
		continue;
		}
		if (i==612) {
		rv612=randomVar;
		continue;
		}
		if (i==613) {
		rv613=randomVar;
		continue;
		}
		if (i==614) {
		rv614=randomVar;
		continue;
		}
		if (i==615) {
		rv615=randomVar;
		continue;
		}
		if (i==616) {
		rv616=randomVar;
		continue;
		}
		if (i==617) {
		rv617=randomVar;
		continue;
		}
		if (i==618) {
		rv618=randomVar;
		continue;
		}
		if (i==619) {
		rv619=randomVar;
		continue;
		}
		if (i==620) {
		rv620=randomVar;
		continue;
		}
		if (i==621) {
		rv621=randomVar;
		continue;
		}
		if (i==622) {
		rv622=randomVar;
		continue;
		}
		if (i==623) {
		rv623=randomVar;
		continue;
		}
		if (i==624) {
		rv624=randomVar;
		continue;
		}
		if (i==625) {
		rv625=randomVar;
		continue;
		}
		if (i==626) {
		rv626=randomVar;
		continue;
		}
		if (i==627) {
		rv627=randomVar;
		continue;
		}
		if (i==628) {
		rv628=randomVar;
		continue;
		}
		if (i==629) {
		rv629=randomVar;
		continue;
		}
		if (i==630) {
		rv630=randomVar;
		continue;
		}
		if (i==631) {
		rv631=randomVar;
		continue;
		}
		if (i==632) {
		rv632=randomVar;
		continue;
		}
		if (i==633) {
		rv633=randomVar;
		continue;
		}
		if (i==634) {
		rv634=randomVar;
		continue;
		}
		if (i==635) {
		rv635=randomVar;
		continue;
		}
		if (i==636) {
		rv636=randomVar;
		continue;
		}
		if (i==637) {
		rv637=randomVar;
		continue;
		}
		if (i==638) {
		rv638=randomVar;
		continue;
		}
		if (i==639) {
		rv639=randomVar;
		continue;
		}
		if (i==640) {
		rv640=randomVar;
		continue;
		}
		if (i==641) {
		rv641=randomVar;
		continue;
		}
		if (i==642) {
		rv642=randomVar;
		continue;
		}
		if (i==643) {
		rv643=randomVar;
		continue;
		}
		if (i==644) {
		rv644=randomVar;
		continue;
		}
		if (i==645) {
		rv645=randomVar;
		continue;
		}
		if (i==646) {
		rv646=randomVar;
		continue;
		}
		if (i==647) {
		rv647=randomVar;
		continue;
		}
		if (i==648) {
		rv648=randomVar;
		continue;
		}
		if (i==649) {
		rv649=randomVar;
		continue;
		}
		if (i==650) {
		rv650=randomVar;
		continue;
		}
		if (i==651) {
		rv651=randomVar;
		continue;
		}
		if (i==652) {
		rv652=randomVar;
		continue;
		}
		if (i==653) {
		rv653=randomVar;
		continue;
		}
		if (i==654) {
		rv654=randomVar;
		continue;
		}
		if (i==655) {
		rv655=randomVar;
		continue;
		}
		if (i==656) {
		rv656=randomVar;
		continue;
		}
		if (i==657) {
		rv657=randomVar;
		continue;
		}
		if (i==658) {
		rv658=randomVar;
		continue;
		}
		if (i==659) {
		rv659=randomVar;
		continue;
		}
		if (i==660) {
		rv660=randomVar;
		continue;
		}
		if (i==661) {
		rv661=randomVar;
		continue;
		}
		if (i==662) {
		rv662=randomVar;
		continue;
		}
		if (i==663) {
		rv663=randomVar;
		continue;
		}
		if (i==664) {
		rv664=randomVar;
		continue;
		}
		if (i==665) {
		rv665=randomVar;
		continue;
		}
		if (i==666) {
		rv666=randomVar;
		continue;
		}
		if (i==667) {
		rv667=randomVar;
		continue;
		}
		if (i==668) {
		rv668=randomVar;
		continue;
		}
		if (i==669) {
		rv669=randomVar;
		continue;
		}
		if (i==670) {
		rv670=randomVar;
		continue;
		}
		if (i==671) {
		rv671=randomVar;
		continue;
		}
		if (i==672) {
		rv672=randomVar;
		continue;
		}
		if (i==673) {
		rv673=randomVar;
		continue;
		}
		if (i==674) {
		rv674=randomVar;
		continue;
		}
		if (i==675) {
		rv675=randomVar;
		continue;
		}
		if (i==676) {
		rv676=randomVar;
		continue;
		}
		if (i==677) {
		rv677=randomVar;
		continue;
		}
		if (i==678) {
		rv678=randomVar;
		continue;
		}
		if (i==679) {
		rv679=randomVar;
		continue;
		}
		if (i==680) {
		rv680=randomVar;
		continue;
		}
		if (i==681) {
		rv681=randomVar;
		continue;
		}
		if (i==682) {
		rv682=randomVar;
		continue;
		}
		if (i==683) {
		rv683=randomVar;
		continue;
		}
		if (i==684) {
		rv684=randomVar;
		continue;
		}
		if (i==685) {
		rv685=randomVar;
		continue;
		}
		if (i==686) {
		rv686=randomVar;
		continue;
		}
		if (i==687) {
		rv687=randomVar;
		continue;
		}
		if (i==688) {
		rv688=randomVar;
		continue;
		}
		if (i==689) {
		rv689=randomVar;
		continue;
		}
		if (i==690) {
		rv690=randomVar;
		continue;
		}
		if (i==691) {
		rv691=randomVar;
		continue;
		}
		if (i==692) {
		rv692=randomVar;
		continue;
		}
		if (i==693) {
		rv693=randomVar;
		continue;
		}
		if (i==694) {
		rv694=randomVar;
		continue;
		}
		if (i==695) {
		rv695=randomVar;
		continue;
		}
		if (i==696) {
		rv696=randomVar;
		continue;
		}
		if (i==697) {
		rv697=randomVar;
		continue;
		}
		if (i==698) {
		rv698=randomVar;
		continue;
		}
		if (i==699) {
		rv699=randomVar;
		continue;
		}
		if (i==700) {
		rv700=randomVar;
		continue;
		}
		if (i==701) {
		rv701=randomVar;
		continue;
		}
		if (i==702) {
		rv702=randomVar;
		continue;
		}
		if (i==703) {
		rv703=randomVar;
		continue;
		}
		if (i==704) {
		rv704=randomVar;
		continue;
		}
		if (i==705) {
		rv705=randomVar;
		continue;
		}
		if (i==706) {
		rv706=randomVar;
		continue;
		}
		if (i==707) {
		rv707=randomVar;
		continue;
		}
		if (i==708) {
		rv708=randomVar;
		continue;
		}
		if (i==709) {
		rv709=randomVar;
		continue;
		}
		if (i==710) {
		rv710=randomVar;
		continue;
		}
		if (i==711) {
		rv711=randomVar;
		continue;
		}
		if (i==712) {
		rv712=randomVar;
		continue;
		}
		if (i==713) {
		rv713=randomVar;
		continue;
		}
		if (i==714) {
		rv714=randomVar;
		continue;
		}
		if (i==715) {
		rv715=randomVar;
		continue;
		}
		if (i==716) {
		rv716=randomVar;
		continue;
		}
		if (i==717) {
		rv717=randomVar;
		continue;
		}
		if (i==718) {
		rv718=randomVar;
		continue;
		}
		if (i==719) {
		rv719=randomVar;
		continue;
		}
		if (i==720) {
		rv720=randomVar;
		continue;
		}
		if (i==721) {
		rv721=randomVar;
		continue;
		}
		if (i==722) {
		rv722=randomVar;
		continue;
		}
		if (i==723) {
		rv723=randomVar;
		continue;
		}
		if (i==724) {
		rv724=randomVar;
		continue;
		}
		if (i==725) {
		rv725=randomVar;
		continue;
		}
		if (i==726) {
		rv726=randomVar;
		continue;
		}
		if (i==727) {
		rv727=randomVar;
		continue;
		}
		if (i==728) {
		rv728=randomVar;
		continue;
		}
		if (i==729) {
		rv729=randomVar;
		continue;
		}
		if (i==730) {
		rv730=randomVar;
		continue;
		}
		if (i==731) {
		rv731=randomVar;
		continue;
		}
		if (i==732) {
		rv732=randomVar;
		continue;
		}
		if (i==733) {
		rv733=randomVar;
		continue;
		}
		if (i==734) {
		rv734=randomVar;
		continue;
		}
		if (i==735) {
		rv735=randomVar;
		continue;
		}
		if (i==736) {
		rv736=randomVar;
		continue;
		}
		if (i==737) {
		rv737=randomVar;
		continue;
		}
		if (i==738) {
		rv738=randomVar;
		continue;
		}
		if (i==739) {
		rv739=randomVar;
		continue;
		}
		if (i==740) {
		rv740=randomVar;
		continue;
		}
		if (i==741) {
		rv741=randomVar;
		continue;
		}
		if (i==742) {
		rv742=randomVar;
		continue;
		}
		if (i==743) {
		rv743=randomVar;
		continue;
		}
		if (i==744) {
		rv744=randomVar;
		continue;
		}
		if (i==745) {
		rv745=randomVar;
		continue;
		}
		if (i==746) {
		rv746=randomVar;
		continue;
		}
		if (i==747) {
		rv747=randomVar;
		continue;
		}
		if (i==748) {
		rv748=randomVar;
		continue;
		}
		if (i==749) {
		rv749=randomVar;
		continue;
		}
		if (i==750) {
		rv750=randomVar;
		continue;
		}
		if (i==751) {
		rv751=randomVar;
		continue;
		}
		if (i==752) {
		rv752=randomVar;
		continue;
		}
		if (i==753) {
		rv753=randomVar;
		continue;
		}
		if (i==754) {
		rv754=randomVar;
		continue;
		}
		if (i==755) {
		rv755=randomVar;
		continue;
		}
		if (i==756) {
		rv756=randomVar;
		continue;
		}
		if (i==757) {
		rv757=randomVar;
		continue;
		}
		if (i==758) {
		rv758=randomVar;
		continue;
		}
		if (i==759) {
		rv759=randomVar;
		continue;
		}
		if (i==760) {
		rv760=randomVar;
		continue;
		}
		if (i==761) {
		rv761=randomVar;
		continue;
		}
		if (i==762) {
		rv762=randomVar;
		continue;
		}
		if (i==763) {
		rv763=randomVar;
		continue;
		}
		if (i==764) {
		rv764=randomVar;
		continue;
		}
		if (i==765) {
		rv765=randomVar;
		continue;
		}
		if (i==766) {
		rv766=randomVar;
		continue;
		}
		if (i==767) {
		rv767=randomVar;
		continue;
		}
		if (i==768) {
		rv768=randomVar;
		continue;
		}
		if (i==769) {
		rv769=randomVar;
		continue;
		}
		if (i==770) {
		rv770=randomVar;
		continue;
		}
		if (i==771) {
		rv771=randomVar;
		continue;
		}
		if (i==772) {
		rv772=randomVar;
		continue;
		}
		if (i==773) {
		rv773=randomVar;
		continue;
		}
		if (i==774) {
		rv774=randomVar;
		continue;
		}
		if (i==775) {
		rv775=randomVar;
		continue;
		}
		if (i==776) {
		rv776=randomVar;
		continue;
		}
		if (i==777) {
		rv777=randomVar;
		continue;
		}
		if (i==778) {
		rv778=randomVar;
		continue;
		}
		if (i==779) {
		rv779=randomVar;
		continue;
		}
		if (i==780) {
		rv780=randomVar;
		continue;
		}
		if (i==781) {
		rv781=randomVar;
		continue;
		}
		if (i==782) {
		rv782=randomVar;
		continue;
		}
		if (i==783) {
		rv783=randomVar;
		continue;
		}
		if (i==784) {
		rv784=randomVar;
		continue;
		}
		if (i==785) {
		rv785=randomVar;
		continue;
		}
		if (i==786) {
		rv786=randomVar;
		continue;
		}
		if (i==787) {
		rv787=randomVar;
		continue;
		}
		if (i==788) {
		rv788=randomVar;
		continue;
		}
		if (i==789) {
		rv789=randomVar;
		continue;
		}
		if (i==790) {
		rv790=randomVar;
		continue;
		}
		if (i==791) {
		rv791=randomVar;
		continue;
		}
		if (i==792) {
		rv792=randomVar;
		continue;
		}
		if (i==793) {
		rv793=randomVar;
		continue;
		}
		if (i==794) {
		rv794=randomVar;
		continue;
		}
		if (i==795) {
		rv795=randomVar;
		continue;
		}
		if (i==796) {
		rv796=randomVar;
		continue;
		}
		if (i==797) {
		rv797=randomVar;
		continue;
		}
		if (i==798) {
		rv798=randomVar;
		continue;
		}
		if (i==799) {
		rv799=randomVar;
		continue;
		}
		if (i==800) {
		rv800=randomVar;
		continue;
		}
		if (i==801) {
		rv801=randomVar;
		continue;
		}
		if (i==802) {
		rv802=randomVar;
		continue;
		}
		if (i==803) {
		rv803=randomVar;
		continue;
		}
		if (i==804) {
		rv804=randomVar;
		continue;
		}
		if (i==805) {
		rv805=randomVar;
		continue;
		}
		if (i==806) {
		rv806=randomVar;
		continue;
		}
		if (i==807) {
		rv807=randomVar;
		continue;
		}
		if (i==808) {
		rv808=randomVar;
		continue;
		}
		if (i==809) {
		rv809=randomVar;
		continue;
		}
		if (i==810) {
		rv810=randomVar;
		continue;
		}
		if (i==811) {
		rv811=randomVar;
		continue;
		}
		if (i==812) {
		rv812=randomVar;
		continue;
		}
		if (i==813) {
		rv813=randomVar;
		continue;
		}
		if (i==814) {
		rv814=randomVar;
		continue;
		}
		if (i==815) {
		rv815=randomVar;
		continue;
		}
		if (i==816) {
		rv816=randomVar;
		continue;
		}
		if (i==817) {
		rv817=randomVar;
		continue;
		}
		if (i==818) {
		rv818=randomVar;
		continue;
		}
		if (i==819) {
		rv819=randomVar;
		continue;
		}
		if (i==820) {
		rv820=randomVar;
		continue;
		}
		if (i==821) {
		rv821=randomVar;
		continue;
		}
		if (i==822) {
		rv822=randomVar;
		continue;
		}
		if (i==823) {
		rv823=randomVar;
		continue;
		}
		if (i==824) {
		rv824=randomVar;
		continue;
		}
		if (i==825) {
		rv825=randomVar;
		continue;
		}
		if (i==826) {
		rv826=randomVar;
		continue;
		}
		if (i==827) {
		rv827=randomVar;
		continue;
		}
		if (i==828) {
		rv828=randomVar;
		continue;
		}
		if (i==829) {
		rv829=randomVar;
		continue;
		}
		if (i==830) {
		rv830=randomVar;
		continue;
		}
		if (i==831) {
		rv831=randomVar;
		continue;
		}
		if (i==832) {
		rv832=randomVar;
		continue;
		}
		if (i==833) {
		rv833=randomVar;
		continue;
		}
		if (i==834) {
		rv834=randomVar;
		continue;
		}
		if (i==835) {
		rv835=randomVar;
		continue;
		}
		if (i==836) {
		rv836=randomVar;
		continue;
		}
		if (i==837) {
		rv837=randomVar;
		continue;
		}
		if (i==838) {
		rv838=randomVar;
		continue;
		}
		if (i==839) {
		rv839=randomVar;
		continue;
		}
		if (i==840) {
		rv840=randomVar;
		continue;
		}
		if (i==841) {
		rv841=randomVar;
		continue;
		}
		if (i==842) {
		rv842=randomVar;
		continue;
		}
		if (i==843) {
		rv843=randomVar;
		continue;
		}
		if (i==844) {
		rv844=randomVar;
		continue;
		}
		if (i==845) {
		rv845=randomVar;
		continue;
		}
		if (i==846) {
		rv846=randomVar;
		continue;
		}
		if (i==847) {
		rv847=randomVar;
		continue;
		}
		if (i==848) {
		rv848=randomVar;
		continue;
		}
		if (i==849) {
		rv849=randomVar;
		continue;
		}
		if (i==850) {
		rv850=randomVar;
		continue;
		}
		if (i==851) {
		rv851=randomVar;
		continue;
		}
		if (i==852) {
		rv852=randomVar;
		continue;
		}
		if (i==853) {
		rv853=randomVar;
		continue;
		}
		if (i==854) {
		rv854=randomVar;
		continue;
		}
		if (i==855) {
		rv855=randomVar;
		continue;
		}
		if (i==856) {
		rv856=randomVar;
		continue;
		}
		if (i==857) {
		rv857=randomVar;
		continue;
		}
		if (i==858) {
		rv858=randomVar;
		continue;
		}
		if (i==859) {
		rv859=randomVar;
		continue;
		}
		if (i==860) {
		rv860=randomVar;
		continue;
		}
		if (i==861) {
		rv861=randomVar;
		continue;
		}
		if (i==862) {
		rv862=randomVar;
		continue;
		}
		if (i==863) {
		rv863=randomVar;
		continue;
		}
		if (i==864) {
		rv864=randomVar;
		continue;
		}
		if (i==865) {
		rv865=randomVar;
		continue;
		}
		if (i==866) {
		rv866=randomVar;
		continue;
		}
		if (i==867) {
		rv867=randomVar;
		continue;
		}
		if (i==868) {
		rv868=randomVar;
		continue;
		}
		if (i==869) {
		rv869=randomVar;
		continue;
		}
		if (i==870) {
		rv870=randomVar;
		continue;
		}
		if (i==871) {
		rv871=randomVar;
		continue;
		}
		if (i==872) {
		rv872=randomVar;
		continue;
		}
		if (i==873) {
		rv873=randomVar;
		continue;
		}
		if (i==874) {
		rv874=randomVar;
		continue;
		}
		if (i==875) {
		rv875=randomVar;
		continue;
		}
		if (i==876) {
		rv876=randomVar;
		continue;
		}
		if (i==877) {
		rv877=randomVar;
		continue;
		}
		if (i==878) {
		rv878=randomVar;
		continue;
		}
		if (i==879) {
		rv879=randomVar;
		continue;
		}
		if (i==880) {
		rv880=randomVar;
		continue;
		}
		if (i==881) {
		rv881=randomVar;
		continue;
		}
		if (i==882) {
		rv882=randomVar;
		continue;
		}
		if (i==883) {
		rv883=randomVar;
		continue;
		}
		if (i==884) {
		rv884=randomVar;
		continue;
		}
		if (i==885) {
		rv885=randomVar;
		continue;
		}
		if (i==886) {
		rv886=randomVar;
		continue;
		}
		if (i==887) {
		rv887=randomVar;
		continue;
		}
		if (i==888) {
		rv888=randomVar;
		continue;
		}
		if (i==889) {
		rv889=randomVar;
		continue;
		}
		if (i==890) {
		rv890=randomVar;
		continue;
		}
		if (i==891) {
		rv891=randomVar;
		continue;
		}
		if (i==892) {
		rv892=randomVar;
		continue;
		}
		if (i==893) {
		rv893=randomVar;
		continue;
		}
		if (i==894) {
		rv894=randomVar;
		continue;
		}
		if (i==895) {
		rv895=randomVar;
		continue;
		}
		if (i==896) {
		rv896=randomVar;
		continue;
		}
		if (i==897) {
		rv897=randomVar;
		continue;
		}
		if (i==898) {
		rv898=randomVar;
		continue;
		}
		if (i==899) {
		rv899=randomVar;
		continue;
		}
		if (i==900) {
		rv900=randomVar;
		continue;
		}
		if (i==901) {
		rv901=randomVar;
		continue;
		}
		if (i==902) {
		rv902=randomVar;
		continue;
		}
		if (i==903) {
		rv903=randomVar;
		continue;
		}
		if (i==904) {
		rv904=randomVar;
		continue;
		}
		if (i==905) {
		rv905=randomVar;
		continue;
		}
		if (i==906) {
		rv906=randomVar;
		continue;
		}
		if (i==907) {
		rv907=randomVar;
		continue;
		}
		if (i==908) {
		rv908=randomVar;
		continue;
		}
		if (i==909) {
		rv909=randomVar;
		continue;
		}
		if (i==910) {
		rv910=randomVar;
		continue;
		}
		if (i==911) {
		rv911=randomVar;
		continue;
		}
		if (i==912) {
		rv912=randomVar;
		continue;
		}
		if (i==913) {
		rv913=randomVar;
		continue;
		}
		if (i==914) {
		rv914=randomVar;
		continue;
		}
		if (i==915) {
		rv915=randomVar;
		continue;
		}
		if (i==916) {
		rv916=randomVar;
		continue;
		}
		if (i==917) {
		rv917=randomVar;
		continue;
		}
		if (i==918) {
		rv918=randomVar;
		continue;
		}
		if (i==919) {
		rv919=randomVar;
		continue;
		}
		if (i==920) {
		rv920=randomVar;
		continue;
		}
		if (i==921) {
		rv921=randomVar;
		continue;
		}
		if (i==922) {
		rv922=randomVar;
		continue;
		}
		if (i==923) {
		rv923=randomVar;
		continue;
		}
		if (i==924) {
		rv924=randomVar;
		continue;
		}
		if (i==925) {
		rv925=randomVar;
		continue;
		}
		if (i==926) {
		rv926=randomVar;
		continue;
		}
		if (i==927) {
		rv927=randomVar;
		continue;
		}
		if (i==928) {
		rv928=randomVar;
		continue;
		}
		if (i==929) {
		rv929=randomVar;
		continue;
		}
		if (i==930) {
		rv930=randomVar;
		continue;
		}
		if (i==931) {
		rv931=randomVar;
		continue;
		}
		if (i==932) {
		rv932=randomVar;
		continue;
		}
		if (i==933) {
		rv933=randomVar;
		continue;
		}
		if (i==934) {
		rv934=randomVar;
		continue;
		}
		if (i==935) {
		rv935=randomVar;
		continue;
		}
		if (i==936) {
		rv936=randomVar;
		continue;
		}
		if (i==937) {
		rv937=randomVar;
		continue;
		}
		if (i==938) {
		rv938=randomVar;
		continue;
		}
		if (i==939) {
		rv939=randomVar;
		continue;
		}
		if (i==940) {
		rv940=randomVar;
		continue;
		}
		if (i==941) {
		rv941=randomVar;
		continue;
		}
		if (i==942) {
		rv942=randomVar;
		continue;
		}
		if (i==943) {
		rv943=randomVar;
		continue;
		}
		if (i==944) {
		rv944=randomVar;
		continue;
		}
		if (i==945) {
		rv945=randomVar;
		continue;
		}
		if (i==946) {
		rv946=randomVar;
		continue;
		}
		if (i==947) {
		rv947=randomVar;
		continue;
		}
		if (i==948) {
		rv948=randomVar;
		continue;
		}
		if (i==949) {
		rv949=randomVar;
		continue;
		}
		if (i==950) {
		rv950=randomVar;
		continue;
		}
		if (i==951) {
		rv951=randomVar;
		continue;
		}
		if (i==952) {
		rv952=randomVar;
		continue;
		}
		if (i==953) {
		rv953=randomVar;
		continue;
		}
		if (i==954) {
		rv954=randomVar;
		continue;
		}
		if (i==955) {
		rv955=randomVar;
		continue;
		}
		if (i==956) {
		rv956=randomVar;
		continue;
		}
		if (i==957) {
		rv957=randomVar;
		continue;
		}
		if (i==958) {
		rv958=randomVar;
		continue;
		}
		if (i==959) {
		rv959=randomVar;
		continue;
		}
		if (i==960) {
		rv960=randomVar;
		continue;
		}
		if (i==961) {
		rv961=randomVar;
		continue;
		}
		if (i==962) {
		rv962=randomVar;
		continue;
		}
		if (i==963) {
		rv963=randomVar;
		continue;
		}
		if (i==964) {
		rv964=randomVar;
		continue;
		}
		if (i==965) {
		rv965=randomVar;
		continue;
		}
		if (i==966) {
		rv966=randomVar;
		continue;
		}
		if (i==967) {
		rv967=randomVar;
		continue;
		}
		if (i==968) {
		rv968=randomVar;
		continue;
		}
		if (i==969) {
		rv969=randomVar;
		continue;
		}
		if (i==970) {
		rv970=randomVar;
		continue;
		}
		if (i==971) {
		rv971=randomVar;
		continue;
		}
		if (i==972) {
		rv972=randomVar;
		continue;
		}
		if (i==973) {
		rv973=randomVar;
		continue;
		}
		if (i==974) {
		rv974=randomVar;
		continue;
		}
		if (i==975) {
		rv975=randomVar;
		continue;
		}
		if (i==976) {
		rv976=randomVar;
		continue;
		}
		if (i==977) {
		rv977=randomVar;
		continue;
		}
		if (i==978) {
		rv978=randomVar;
		continue;
		}
		if (i==979) {
		rv979=randomVar;
		continue;
		}
		if (i==980) {
		rv980=randomVar;
		continue;
		}
		if (i==981) {
		rv981=randomVar;
		continue;
		}
		if (i==982) {
		rv982=randomVar;
		continue;
		}
		if (i==983) {
		rv983=randomVar;
		continue;
		}
		if (i==984) {
		rv984=randomVar;
		continue;
		}
		if (i==985) {
		rv985=randomVar;
		continue;
		}
		if (i==986) {
		rv986=randomVar;
		continue;
		}
		if (i==987) {
		rv987=randomVar;
		continue;
		}
		if (i==988) {
		rv988=randomVar;
		continue;
		}
		if (i==989) {
		rv989=randomVar;
		continue;
		}
		if (i==990) {
		rv990=randomVar;
		continue;
		}
		if (i==991) {
		rv991=randomVar;
		continue;
		}
		if (i==992) {
		rv992=randomVar;
		continue;
		}
		if (i==993) {
		rv993=randomVar;
		continue;
		}
		if (i==994) {
		rv994=randomVar;
		continue;
		}
		if (i==995) {
		rv995=randomVar;
		continue;
		}
		if (i==996) {
		rv996=randomVar;
		continue;
		}
		if (i==997) {
		rv997=randomVar;
		continue;
		}
		if (i==998) {
		rv998=randomVar;
		continue;
		}
		if (i==999) {
		rv999=randomVar;
		continue;
		}
	}

	// Calculate amount of A, C, T, G nucleotides by their percentages
	int a = round((double)pA*rVarSum);
	int c = round((double)pC*rVarSum);
	int t = round((double)pT*rVarSum);
	int g = round((double)pG*rVarSum);
	ofstream o;
	o.open("xaviablaza.out", ofstream::out | ofstream::app);
	int lineLength;
	for (int j=0; j<amount; ++j) {
		if (j==0) {
		lineLength=rv0;
		} else 
		if (j==1) {
		lineLength=rv1;
		} else 
		if (j==2) {
		lineLength=rv2;
		} else 
		if (j==3) {
		lineLength=rv3;
		} else 
		if (j==4) {
		lineLength=rv4;
		} else 
		if (j==5) {
		lineLength=rv5;
		} else 
		if (j==6) {
		lineLength=rv6;
		} else 
		if (j==7) {
		lineLength=rv7;
		} else 
		if (j==8) {
		lineLength=rv8;
		} else 
		if (j==9) {
		lineLength=rv9;
		} else 
		if (j==10) {
		lineLength=rv10;
		} else 
		if (j==11) {
		lineLength=rv11;
		} else 
		if (j==12) {
		lineLength=rv12;
		} else 
		if (j==13) {
		lineLength=rv13;
		} else 
		if (j==14) {
		lineLength=rv14;
		} else 
		if (j==15) {
		lineLength=rv15;
		} else 
		if (j==16) {
		lineLength=rv16;
		} else 
		if (j==17) {
		lineLength=rv17;
		} else 
		if (j==18) {
		lineLength=rv18;
		} else 
		if (j==19) {
		lineLength=rv19;
		} else 
		if (j==20) {
		lineLength=rv20;
		} else 
		if (j==21) {
		lineLength=rv21;
		} else 
		if (j==22) {
		lineLength=rv22;
		} else 
		if (j==23) {
		lineLength=rv23;
		} else 
		if (j==24) {
		lineLength=rv24;
		} else 
		if (j==25) {
		lineLength=rv25;
		} else 
		if (j==26) {
		lineLength=rv26;
		} else 
		if (j==27) {
		lineLength=rv27;
		} else 
		if (j==28) {
		lineLength=rv28;
		} else 
		if (j==29) {
		lineLength=rv29;
		} else 
		if (j==30) {
		lineLength=rv30;
		} else 
		if (j==31) {
		lineLength=rv31;
		} else 
		if (j==32) {
		lineLength=rv32;
		} else 
		if (j==33) {
		lineLength=rv33;
		} else 
		if (j==34) {
		lineLength=rv34;
		} else 
		if (j==35) {
		lineLength=rv35;
		} else 
		if (j==36) {
		lineLength=rv36;
		} else 
		if (j==37) {
		lineLength=rv37;
		} else 
		if (j==38) {
		lineLength=rv38;
		} else 
		if (j==39) {
		lineLength=rv39;
		} else 
		if (j==40) {
		lineLength=rv40;
		} else 
		if (j==41) {
		lineLength=rv41;
		} else 
		if (j==42) {
		lineLength=rv42;
		} else 
		if (j==43) {
		lineLength=rv43;
		} else 
		if (j==44) {
		lineLength=rv44;
		} else 
		if (j==45) {
		lineLength=rv45;
		} else 
		if (j==46) {
		lineLength=rv46;
		} else 
		if (j==47) {
		lineLength=rv47;
		} else 
		if (j==48) {
		lineLength=rv48;
		} else 
		if (j==49) {
		lineLength=rv49;
		} else 
		if (j==50) {
		lineLength=rv50;
		} else 
		if (j==51) {
		lineLength=rv51;
		} else 
		if (j==52) {
		lineLength=rv52;
		} else 
		if (j==53) {
		lineLength=rv53;
		} else 
		if (j==54) {
		lineLength=rv54;
		} else 
		if (j==55) {
		lineLength=rv55;
		} else 
		if (j==56) {
		lineLength=rv56;
		} else 
		if (j==57) {
		lineLength=rv57;
		} else 
		if (j==58) {
		lineLength=rv58;
		} else 
		if (j==59) {
		lineLength=rv59;
		} else 
		if (j==60) {
		lineLength=rv60;
		} else 
		if (j==61) {
		lineLength=rv61;
		} else 
		if (j==62) {
		lineLength=rv62;
		} else 
		if (j==63) {
		lineLength=rv63;
		} else 
		if (j==64) {
		lineLength=rv64;
		} else 
		if (j==65) {
		lineLength=rv65;
		} else 
		if (j==66) {
		lineLength=rv66;
		} else 
		if (j==67) {
		lineLength=rv67;
		} else 
		if (j==68) {
		lineLength=rv68;
		} else 
		if (j==69) {
		lineLength=rv69;
		} else 
		if (j==70) {
		lineLength=rv70;
		} else 
		if (j==71) {
		lineLength=rv71;
		} else 
		if (j==72) {
		lineLength=rv72;
		} else 
		if (j==73) {
		lineLength=rv73;
		} else 
		if (j==74) {
		lineLength=rv74;
		} else 
		if (j==75) {
		lineLength=rv75;
		} else 
		if (j==76) {
		lineLength=rv76;
		} else 
		if (j==77) {
		lineLength=rv77;
		} else 
		if (j==78) {
		lineLength=rv78;
		} else 
		if (j==79) {
		lineLength=rv79;
		} else 
		if (j==80) {
		lineLength=rv80;
		} else 
		if (j==81) {
		lineLength=rv81;
		} else 
		if (j==82) {
		lineLength=rv82;
		} else 
		if (j==83) {
		lineLength=rv83;
		} else 
		if (j==84) {
		lineLength=rv84;
		} else 
		if (j==85) {
		lineLength=rv85;
		} else 
		if (j==86) {
		lineLength=rv86;
		} else 
		if (j==87) {
		lineLength=rv87;
		} else 
		if (j==88) {
		lineLength=rv88;
		} else 
		if (j==89) {
		lineLength=rv89;
		} else 
		if (j==90) {
		lineLength=rv90;
		} else 
		if (j==91) {
		lineLength=rv91;
		} else 
		if (j==92) {
		lineLength=rv92;
		} else 
		if (j==93) {
		lineLength=rv93;
		} else 
		if (j==94) {
		lineLength=rv94;
		} else 
		if (j==95) {
		lineLength=rv95;
		} else 
		if (j==96) {
		lineLength=rv96;
		} else 
		if (j==97) {
		lineLength=rv97;
		} else 
		if (j==98) {
		lineLength=rv98;
		} else 
		if (j==99) {
		lineLength=rv99;
		} else 
		if (j==100) {
		lineLength=rv100;
		} else 
		if (j==101) {
		lineLength=rv101;
		} else 
		if (j==102) {
		lineLength=rv102;
		} else 
		if (j==103) {
		lineLength=rv103;
		} else 
		if (j==104) {
		lineLength=rv104;
		} else 
		if (j==105) {
		lineLength=rv105;
		} else 
		if (j==106) {
		lineLength=rv106;
		} else 
		if (j==107) {
		lineLength=rv107;
		} else 
		if (j==108) {
		lineLength=rv108;
		} else 
		if (j==109) {
		lineLength=rv109;
		} else 
		if (j==110) {
		lineLength=rv110;
		} else 
		if (j==111) {
		lineLength=rv111;
		} else 
		if (j==112) {
		lineLength=rv112;
		} else 
		if (j==113) {
		lineLength=rv113;
		} else 
		if (j==114) {
		lineLength=rv114;
		} else 
		if (j==115) {
		lineLength=rv115;
		} else 
		if (j==116) {
		lineLength=rv116;
		} else 
		if (j==117) {
		lineLength=rv117;
		} else 
		if (j==118) {
		lineLength=rv118;
		} else 
		if (j==119) {
		lineLength=rv119;
		} else 
		if (j==120) {
		lineLength=rv120;
		} else 
		if (j==121) {
		lineLength=rv121;
		} else 
		if (j==122) {
		lineLength=rv122;
		} else 
		if (j==123) {
		lineLength=rv123;
		} else 
		if (j==124) {
		lineLength=rv124;
		} else 
		if (j==125) {
		lineLength=rv125;
		} else 
		if (j==126) {
		lineLength=rv126;
		} else 
		if (j==127) {
		lineLength=rv127;
		} else 
		if (j==128) {
		lineLength=rv128;
		} else 
		if (j==129) {
		lineLength=rv129;
		} else 
		if (j==130) {
		lineLength=rv130;
		} else 
		if (j==131) {
		lineLength=rv131;
		} else 
		if (j==132) {
		lineLength=rv132;
		} else 
		if (j==133) {
		lineLength=rv133;
		} else 
		if (j==134) {
		lineLength=rv134;
		} else 
		if (j==135) {
		lineLength=rv135;
		} else 
		if (j==136) {
		lineLength=rv136;
		} else 
		if (j==137) {
		lineLength=rv137;
		} else 
		if (j==138) {
		lineLength=rv138;
		} else 
		if (j==139) {
		lineLength=rv139;
		} else 
		if (j==140) {
		lineLength=rv140;
		} else 
		if (j==141) {
		lineLength=rv141;
		} else 
		if (j==142) {
		lineLength=rv142;
		} else 
		if (j==143) {
		lineLength=rv143;
		} else 
		if (j==144) {
		lineLength=rv144;
		} else 
		if (j==145) {
		lineLength=rv145;
		} else 
		if (j==146) {
		lineLength=rv146;
		} else 
		if (j==147) {
		lineLength=rv147;
		} else 
		if (j==148) {
		lineLength=rv148;
		} else 
		if (j==149) {
		lineLength=rv149;
		} else 
		if (j==150) {
		lineLength=rv150;
		} else 
		if (j==151) {
		lineLength=rv151;
		} else 
		if (j==152) {
		lineLength=rv152;
		} else 
		if (j==153) {
		lineLength=rv153;
		} else 
		if (j==154) {
		lineLength=rv154;
		} else 
		if (j==155) {
		lineLength=rv155;
		} else 
		if (j==156) {
		lineLength=rv156;
		} else 
		if (j==157) {
		lineLength=rv157;
		} else 
		if (j==158) {
		lineLength=rv158;
		} else 
		if (j==159) {
		lineLength=rv159;
		} else 
		if (j==160) {
		lineLength=rv160;
		} else 
		if (j==161) {
		lineLength=rv161;
		} else 
		if (j==162) {
		lineLength=rv162;
		} else 
		if (j==163) {
		lineLength=rv163;
		} else 
		if (j==164) {
		lineLength=rv164;
		} else 
		if (j==165) {
		lineLength=rv165;
		} else 
		if (j==166) {
		lineLength=rv166;
		} else 
		if (j==167) {
		lineLength=rv167;
		} else 
		if (j==168) {
		lineLength=rv168;
		} else 
		if (j==169) {
		lineLength=rv169;
		} else 
		if (j==170) {
		lineLength=rv170;
		} else 
		if (j==171) {
		lineLength=rv171;
		} else 
		if (j==172) {
		lineLength=rv172;
		} else 
		if (j==173) {
		lineLength=rv173;
		} else 
		if (j==174) {
		lineLength=rv174;
		} else 
		if (j==175) {
		lineLength=rv175;
		} else 
		if (j==176) {
		lineLength=rv176;
		} else 
		if (j==177) {
		lineLength=rv177;
		} else 
		if (j==178) {
		lineLength=rv178;
		} else 
		if (j==179) {
		lineLength=rv179;
		} else 
		if (j==180) {
		lineLength=rv180;
		} else 
		if (j==181) {
		lineLength=rv181;
		} else 
		if (j==182) {
		lineLength=rv182;
		} else 
		if (j==183) {
		lineLength=rv183;
		} else 
		if (j==184) {
		lineLength=rv184;
		} else 
		if (j==185) {
		lineLength=rv185;
		} else 
		if (j==186) {
		lineLength=rv186;
		} else 
		if (j==187) {
		lineLength=rv187;
		} else 
		if (j==188) {
		lineLength=rv188;
		} else 
		if (j==189) {
		lineLength=rv189;
		} else 
		if (j==190) {
		lineLength=rv190;
		} else 
		if (j==191) {
		lineLength=rv191;
		} else 
		if (j==192) {
		lineLength=rv192;
		} else 
		if (j==193) {
		lineLength=rv193;
		} else 
		if (j==194) {
		lineLength=rv194;
		} else 
		if (j==195) {
		lineLength=rv195;
		} else 
		if (j==196) {
		lineLength=rv196;
		} else 
		if (j==197) {
		lineLength=rv197;
		} else 
		if (j==198) {
		lineLength=rv198;
		} else 
		if (j==199) {
		lineLength=rv199;
		} else 
		if (j==200) {
		lineLength=rv200;
		} else 
		if (j==201) {
		lineLength=rv201;
		} else 
		if (j==202) {
		lineLength=rv202;
		} else 
		if (j==203) {
		lineLength=rv203;
		} else 
		if (j==204) {
		lineLength=rv204;
		} else 
		if (j==205) {
		lineLength=rv205;
		} else 
		if (j==206) {
		lineLength=rv206;
		} else 
		if (j==207) {
		lineLength=rv207;
		} else 
		if (j==208) {
		lineLength=rv208;
		} else 
		if (j==209) {
		lineLength=rv209;
		} else 
		if (j==210) {
		lineLength=rv210;
		} else 
		if (j==211) {
		lineLength=rv211;
		} else 
		if (j==212) {
		lineLength=rv212;
		} else 
		if (j==213) {
		lineLength=rv213;
		} else 
		if (j==214) {
		lineLength=rv214;
		} else 
		if (j==215) {
		lineLength=rv215;
		} else 
		if (j==216) {
		lineLength=rv216;
		} else 
		if (j==217) {
		lineLength=rv217;
		} else 
		if (j==218) {
		lineLength=rv218;
		} else 
		if (j==219) {
		lineLength=rv219;
		} else 
		if (j==220) {
		lineLength=rv220;
		} else 
		if (j==221) {
		lineLength=rv221;
		} else 
		if (j==222) {
		lineLength=rv222;
		} else 
		if (j==223) {
		lineLength=rv223;
		} else 
		if (j==224) {
		lineLength=rv224;
		} else 
		if (j==225) {
		lineLength=rv225;
		} else 
		if (j==226) {
		lineLength=rv226;
		} else 
		if (j==227) {
		lineLength=rv227;
		} else 
		if (j==228) {
		lineLength=rv228;
		} else 
		if (j==229) {
		lineLength=rv229;
		} else 
		if (j==230) {
		lineLength=rv230;
		} else 
		if (j==231) {
		lineLength=rv231;
		} else 
		if (j==232) {
		lineLength=rv232;
		} else 
		if (j==233) {
		lineLength=rv233;
		} else 
		if (j==234) {
		lineLength=rv234;
		} else 
		if (j==235) {
		lineLength=rv235;
		} else 
		if (j==236) {
		lineLength=rv236;
		} else 
		if (j==237) {
		lineLength=rv237;
		} else 
		if (j==238) {
		lineLength=rv238;
		} else 
		if (j==239) {
		lineLength=rv239;
		} else 
		if (j==240) {
		lineLength=rv240;
		} else 
		if (j==241) {
		lineLength=rv241;
		} else 
		if (j==242) {
		lineLength=rv242;
		} else 
		if (j==243) {
		lineLength=rv243;
		} else 
		if (j==244) {
		lineLength=rv244;
		} else 
		if (j==245) {
		lineLength=rv245;
		} else 
		if (j==246) {
		lineLength=rv246;
		} else 
		if (j==247) {
		lineLength=rv247;
		} else 
		if (j==248) {
		lineLength=rv248;
		} else 
		if (j==249) {
		lineLength=rv249;
		} else 
		if (j==250) {
		lineLength=rv250;
		} else 
		if (j==251) {
		lineLength=rv251;
		} else 
		if (j==252) {
		lineLength=rv252;
		} else 
		if (j==253) {
		lineLength=rv253;
		} else 
		if (j==254) {
		lineLength=rv254;
		} else 
		if (j==255) {
		lineLength=rv255;
		} else 
		if (j==256) {
		lineLength=rv256;
		} else 
		if (j==257) {
		lineLength=rv257;
		} else 
		if (j==258) {
		lineLength=rv258;
		} else 
		if (j==259) {
		lineLength=rv259;
		} else 
		if (j==260) {
		lineLength=rv260;
		} else 
		if (j==261) {
		lineLength=rv261;
		} else 
		if (j==262) {
		lineLength=rv262;
		} else 
		if (j==263) {
		lineLength=rv263;
		} else 
		if (j==264) {
		lineLength=rv264;
		} else 
		if (j==265) {
		lineLength=rv265;
		} else 
		if (j==266) {
		lineLength=rv266;
		} else 
		if (j==267) {
		lineLength=rv267;
		} else 
		if (j==268) {
		lineLength=rv268;
		} else 
		if (j==269) {
		lineLength=rv269;
		} else 
		if (j==270) {
		lineLength=rv270;
		} else 
		if (j==271) {
		lineLength=rv271;
		} else 
		if (j==272) {
		lineLength=rv272;
		} else 
		if (j==273) {
		lineLength=rv273;
		} else 
		if (j==274) {
		lineLength=rv274;
		} else 
		if (j==275) {
		lineLength=rv275;
		} else 
		if (j==276) {
		lineLength=rv276;
		} else 
		if (j==277) {
		lineLength=rv277;
		} else 
		if (j==278) {
		lineLength=rv278;
		} else 
		if (j==279) {
		lineLength=rv279;
		} else 
		if (j==280) {
		lineLength=rv280;
		} else 
		if (j==281) {
		lineLength=rv281;
		} else 
		if (j==282) {
		lineLength=rv282;
		} else 
		if (j==283) {
		lineLength=rv283;
		} else 
		if (j==284) {
		lineLength=rv284;
		} else 
		if (j==285) {
		lineLength=rv285;
		} else 
		if (j==286) {
		lineLength=rv286;
		} else 
		if (j==287) {
		lineLength=rv287;
		} else 
		if (j==288) {
		lineLength=rv288;
		} else 
		if (j==289) {
		lineLength=rv289;
		} else 
		if (j==290) {
		lineLength=rv290;
		} else 
		if (j==291) {
		lineLength=rv291;
		} else 
		if (j==292) {
		lineLength=rv292;
		} else 
		if (j==293) {
		lineLength=rv293;
		} else 
		if (j==294) {
		lineLength=rv294;
		} else 
		if (j==295) {
		lineLength=rv295;
		} else 
		if (j==296) {
		lineLength=rv296;
		} else 
		if (j==297) {
		lineLength=rv297;
		} else 
		if (j==298) {
		lineLength=rv298;
		} else 
		if (j==299) {
		lineLength=rv299;
		} else 
		if (j==300) {
		lineLength=rv300;
		} else 
		if (j==301) {
		lineLength=rv301;
		} else 
		if (j==302) {
		lineLength=rv302;
		} else 
		if (j==303) {
		lineLength=rv303;
		} else 
		if (j==304) {
		lineLength=rv304;
		} else 
		if (j==305) {
		lineLength=rv305;
		} else 
		if (j==306) {
		lineLength=rv306;
		} else 
		if (j==307) {
		lineLength=rv307;
		} else 
		if (j==308) {
		lineLength=rv308;
		} else 
		if (j==309) {
		lineLength=rv309;
		} else 
		if (j==310) {
		lineLength=rv310;
		} else 
		if (j==311) {
		lineLength=rv311;
		} else 
		if (j==312) {
		lineLength=rv312;
		} else 
		if (j==313) {
		lineLength=rv313;
		} else 
		if (j==314) {
		lineLength=rv314;
		} else 
		if (j==315) {
		lineLength=rv315;
		} else 
		if (j==316) {
		lineLength=rv316;
		} else 
		if (j==317) {
		lineLength=rv317;
		} else 
		if (j==318) {
		lineLength=rv318;
		} else 
		if (j==319) {
		lineLength=rv319;
		} else 
		if (j==320) {
		lineLength=rv320;
		} else 
		if (j==321) {
		lineLength=rv321;
		} else 
		if (j==322) {
		lineLength=rv322;
		} else 
		if (j==323) {
		lineLength=rv323;
		} else 
		if (j==324) {
		lineLength=rv324;
		} else 
		if (j==325) {
		lineLength=rv325;
		} else 
		if (j==326) {
		lineLength=rv326;
		} else 
		if (j==327) {
		lineLength=rv327;
		} else 
		if (j==328) {
		lineLength=rv328;
		} else 
		if (j==329) {
		lineLength=rv329;
		} else 
		if (j==330) {
		lineLength=rv330;
		} else 
		if (j==331) {
		lineLength=rv331;
		} else 
		if (j==332) {
		lineLength=rv332;
		} else 
		if (j==333) {
		lineLength=rv333;
		} else 
		if (j==334) {
		lineLength=rv334;
		} else 
		if (j==335) {
		lineLength=rv335;
		} else 
		if (j==336) {
		lineLength=rv336;
		} else 
		if (j==337) {
		lineLength=rv337;
		} else 
		if (j==338) {
		lineLength=rv338;
		} else 
		if (j==339) {
		lineLength=rv339;
		} else 
		if (j==340) {
		lineLength=rv340;
		} else 
		if (j==341) {
		lineLength=rv341;
		} else 
		if (j==342) {
		lineLength=rv342;
		} else 
		if (j==343) {
		lineLength=rv343;
		} else 
		if (j==344) {
		lineLength=rv344;
		} else 
		if (j==345) {
		lineLength=rv345;
		} else 
		if (j==346) {
		lineLength=rv346;
		} else 
		if (j==347) {
		lineLength=rv347;
		} else 
		if (j==348) {
		lineLength=rv348;
		} else 
		if (j==349) {
		lineLength=rv349;
		} else 
		if (j==350) {
		lineLength=rv350;
		} else 
		if (j==351) {
		lineLength=rv351;
		} else 
		if (j==352) {
		lineLength=rv352;
		} else 
		if (j==353) {
		lineLength=rv353;
		} else 
		if (j==354) {
		lineLength=rv354;
		} else 
		if (j==355) {
		lineLength=rv355;
		} else 
		if (j==356) {
		lineLength=rv356;
		} else 
		if (j==357) {
		lineLength=rv357;
		} else 
		if (j==358) {
		lineLength=rv358;
		} else 
		if (j==359) {
		lineLength=rv359;
		} else 
		if (j==360) {
		lineLength=rv360;
		} else 
		if (j==361) {
		lineLength=rv361;
		} else 
		if (j==362) {
		lineLength=rv362;
		} else 
		if (j==363) {
		lineLength=rv363;
		} else 
		if (j==364) {
		lineLength=rv364;
		} else 
		if (j==365) {
		lineLength=rv365;
		} else 
		if (j==366) {
		lineLength=rv366;
		} else 
		if (j==367) {
		lineLength=rv367;
		} else 
		if (j==368) {
		lineLength=rv368;
		} else 
		if (j==369) {
		lineLength=rv369;
		} else 
		if (j==370) {
		lineLength=rv370;
		} else 
		if (j==371) {
		lineLength=rv371;
		} else 
		if (j==372) {
		lineLength=rv372;
		} else 
		if (j==373) {
		lineLength=rv373;
		} else 
		if (j==374) {
		lineLength=rv374;
		} else 
		if (j==375) {
		lineLength=rv375;
		} else 
		if (j==376) {
		lineLength=rv376;
		} else 
		if (j==377) {
		lineLength=rv377;
		} else 
		if (j==378) {
		lineLength=rv378;
		} else 
		if (j==379) {
		lineLength=rv379;
		} else 
		if (j==380) {
		lineLength=rv380;
		} else 
		if (j==381) {
		lineLength=rv381;
		} else 
		if (j==382) {
		lineLength=rv382;
		} else 
		if (j==383) {
		lineLength=rv383;
		} else 
		if (j==384) {
		lineLength=rv384;
		} else 
		if (j==385) {
		lineLength=rv385;
		} else 
		if (j==386) {
		lineLength=rv386;
		} else 
		if (j==387) {
		lineLength=rv387;
		} else 
		if (j==388) {
		lineLength=rv388;
		} else 
		if (j==389) {
		lineLength=rv389;
		} else 
		if (j==390) {
		lineLength=rv390;
		} else 
		if (j==391) {
		lineLength=rv391;
		} else 
		if (j==392) {
		lineLength=rv392;
		} else 
		if (j==393) {
		lineLength=rv393;
		} else 
		if (j==394) {
		lineLength=rv394;
		} else 
		if (j==395) {
		lineLength=rv395;
		} else 
		if (j==396) {
		lineLength=rv396;
		} else 
		if (j==397) {
		lineLength=rv397;
		} else 
		if (j==398) {
		lineLength=rv398;
		} else 
		if (j==399) {
		lineLength=rv399;
		} else 
		if (j==400) {
		lineLength=rv400;
		} else 
		if (j==401) {
		lineLength=rv401;
		} else 
		if (j==402) {
		lineLength=rv402;
		} else 
		if (j==403) {
		lineLength=rv403;
		} else 
		if (j==404) {
		lineLength=rv404;
		} else 
		if (j==405) {
		lineLength=rv405;
		} else 
		if (j==406) {
		lineLength=rv406;
		} else 
		if (j==407) {
		lineLength=rv407;
		} else 
		if (j==408) {
		lineLength=rv408;
		} else 
		if (j==409) {
		lineLength=rv409;
		} else 
		if (j==410) {
		lineLength=rv410;
		} else 
		if (j==411) {
		lineLength=rv411;
		} else 
		if (j==412) {
		lineLength=rv412;
		} else 
		if (j==413) {
		lineLength=rv413;
		} else 
		if (j==414) {
		lineLength=rv414;
		} else 
		if (j==415) {
		lineLength=rv415;
		} else 
		if (j==416) {
		lineLength=rv416;
		} else 
		if (j==417) {
		lineLength=rv417;
		} else 
		if (j==418) {
		lineLength=rv418;
		} else 
		if (j==419) {
		lineLength=rv419;
		} else 
		if (j==420) {
		lineLength=rv420;
		} else 
		if (j==421) {
		lineLength=rv421;
		} else 
		if (j==422) {
		lineLength=rv422;
		} else 
		if (j==423) {
		lineLength=rv423;
		} else 
		if (j==424) {
		lineLength=rv424;
		} else 
		if (j==425) {
		lineLength=rv425;
		} else 
		if (j==426) {
		lineLength=rv426;
		} else 
		if (j==427) {
		lineLength=rv427;
		} else 
		if (j==428) {
		lineLength=rv428;
		} else 
		if (j==429) {
		lineLength=rv429;
		} else 
		if (j==430) {
		lineLength=rv430;
		} else 
		if (j==431) {
		lineLength=rv431;
		} else 
		if (j==432) {
		lineLength=rv432;
		} else 
		if (j==433) {
		lineLength=rv433;
		} else 
		if (j==434) {
		lineLength=rv434;
		} else 
		if (j==435) {
		lineLength=rv435;
		} else 
		if (j==436) {
		lineLength=rv436;
		} else 
		if (j==437) {
		lineLength=rv437;
		} else 
		if (j==438) {
		lineLength=rv438;
		} else 
		if (j==439) {
		lineLength=rv439;
		} else 
		if (j==440) {
		lineLength=rv440;
		} else 
		if (j==441) {
		lineLength=rv441;
		} else 
		if (j==442) {
		lineLength=rv442;
		} else 
		if (j==443) {
		lineLength=rv443;
		} else 
		if (j==444) {
		lineLength=rv444;
		} else 
		if (j==445) {
		lineLength=rv445;
		} else 
		if (j==446) {
		lineLength=rv446;
		} else 
		if (j==447) {
		lineLength=rv447;
		} else 
		if (j==448) {
		lineLength=rv448;
		} else 
		if (j==449) {
		lineLength=rv449;
		} else 
		if (j==450) {
		lineLength=rv450;
		} else 
		if (j==451) {
		lineLength=rv451;
		} else 
		if (j==452) {
		lineLength=rv452;
		} else 
		if (j==453) {
		lineLength=rv453;
		} else 
		if (j==454) {
		lineLength=rv454;
		} else 
		if (j==455) {
		lineLength=rv455;
		} else 
		if (j==456) {
		lineLength=rv456;
		} else 
		if (j==457) {
		lineLength=rv457;
		} else 
		if (j==458) {
		lineLength=rv458;
		} else 
		if (j==459) {
		lineLength=rv459;
		} else 
		if (j==460) {
		lineLength=rv460;
		} else 
		if (j==461) {
		lineLength=rv461;
		} else 
		if (j==462) {
		lineLength=rv462;
		} else 
		if (j==463) {
		lineLength=rv463;
		} else 
		if (j==464) {
		lineLength=rv464;
		} else 
		if (j==465) {
		lineLength=rv465;
		} else 
		if (j==466) {
		lineLength=rv466;
		} else 
		if (j==467) {
		lineLength=rv467;
		} else 
		if (j==468) {
		lineLength=rv468;
		} else 
		if (j==469) {
		lineLength=rv469;
		} else 
		if (j==470) {
		lineLength=rv470;
		} else 
		if (j==471) {
		lineLength=rv471;
		} else 
		if (j==472) {
		lineLength=rv472;
		} else 
		if (j==473) {
		lineLength=rv473;
		} else 
		if (j==474) {
		lineLength=rv474;
		} else 
		if (j==475) {
		lineLength=rv475;
		} else 
		if (j==476) {
		lineLength=rv476;
		} else 
		if (j==477) {
		lineLength=rv477;
		} else 
		if (j==478) {
		lineLength=rv478;
		} else 
		if (j==479) {
		lineLength=rv479;
		} else 
		if (j==480) {
		lineLength=rv480;
		} else 
		if (j==481) {
		lineLength=rv481;
		} else 
		if (j==482) {
		lineLength=rv482;
		} else 
		if (j==483) {
		lineLength=rv483;
		} else 
		if (j==484) {
		lineLength=rv484;
		} else 
		if (j==485) {
		lineLength=rv485;
		} else 
		if (j==486) {
		lineLength=rv486;
		} else 
		if (j==487) {
		lineLength=rv487;
		} else 
		if (j==488) {
		lineLength=rv488;
		} else 
		if (j==489) {
		lineLength=rv489;
		} else 
		if (j==490) {
		lineLength=rv490;
		} else 
		if (j==491) {
		lineLength=rv491;
		} else 
		if (j==492) {
		lineLength=rv492;
		} else 
		if (j==493) {
		lineLength=rv493;
		} else 
		if (j==494) {
		lineLength=rv494;
		} else 
		if (j==495) {
		lineLength=rv495;
		} else 
		if (j==496) {
		lineLength=rv496;
		} else 
		if (j==497) {
		lineLength=rv497;
		} else 
		if (j==498) {
		lineLength=rv498;
		} else 
		if (j==499) {
		lineLength=rv499;
		} else 
		if (j==500) {
		lineLength=rv500;
		} else 
		if (j==501) {
		lineLength=rv501;
		} else 
		if (j==502) {
		lineLength=rv502;
		} else 
		if (j==503) {
		lineLength=rv503;
		} else 
		if (j==504) {
		lineLength=rv504;
		} else 
		if (j==505) {
		lineLength=rv505;
		} else 
		if (j==506) {
		lineLength=rv506;
		} else 
		if (j==507) {
		lineLength=rv507;
		} else 
		if (j==508) {
		lineLength=rv508;
		} else 
		if (j==509) {
		lineLength=rv509;
		} else 
		if (j==510) {
		lineLength=rv510;
		} else 
		if (j==511) {
		lineLength=rv511;
		} else 
		if (j==512) {
		lineLength=rv512;
		} else 
		if (j==513) {
		lineLength=rv513;
		} else 
		if (j==514) {
		lineLength=rv514;
		} else 
		if (j==515) {
		lineLength=rv515;
		} else 
		if (j==516) {
		lineLength=rv516;
		} else 
		if (j==517) {
		lineLength=rv517;
		} else 
		if (j==518) {
		lineLength=rv518;
		} else 
		if (j==519) {
		lineLength=rv519;
		} else 
		if (j==520) {
		lineLength=rv520;
		} else 
		if (j==521) {
		lineLength=rv521;
		} else 
		if (j==522) {
		lineLength=rv522;
		} else 
		if (j==523) {
		lineLength=rv523;
		} else 
		if (j==524) {
		lineLength=rv524;
		} else 
		if (j==525) {
		lineLength=rv525;
		} else 
		if (j==526) {
		lineLength=rv526;
		} else 
		if (j==527) {
		lineLength=rv527;
		} else 
		if (j==528) {
		lineLength=rv528;
		} else 
		if (j==529) {
		lineLength=rv529;
		} else 
		if (j==530) {
		lineLength=rv530;
		} else 
		if (j==531) {
		lineLength=rv531;
		} else 
		if (j==532) {
		lineLength=rv532;
		} else 
		if (j==533) {
		lineLength=rv533;
		} else 
		if (j==534) {
		lineLength=rv534;
		} else 
		if (j==535) {
		lineLength=rv535;
		} else 
		if (j==536) {
		lineLength=rv536;
		} else 
		if (j==537) {
		lineLength=rv537;
		} else 
		if (j==538) {
		lineLength=rv538;
		} else 
		if (j==539) {
		lineLength=rv539;
		} else 
		if (j==540) {
		lineLength=rv540;
		} else 
		if (j==541) {
		lineLength=rv541;
		} else 
		if (j==542) {
		lineLength=rv542;
		} else 
		if (j==543) {
		lineLength=rv543;
		} else 
		if (j==544) {
		lineLength=rv544;
		} else 
		if (j==545) {
		lineLength=rv545;
		} else 
		if (j==546) {
		lineLength=rv546;
		} else 
		if (j==547) {
		lineLength=rv547;
		} else 
		if (j==548) {
		lineLength=rv548;
		} else 
		if (j==549) {
		lineLength=rv549;
		} else 
		if (j==550) {
		lineLength=rv550;
		} else 
		if (j==551) {
		lineLength=rv551;
		} else 
		if (j==552) {
		lineLength=rv552;
		} else 
		if (j==553) {
		lineLength=rv553;
		} else 
		if (j==554) {
		lineLength=rv554;
		} else 
		if (j==555) {
		lineLength=rv555;
		} else 
		if (j==556) {
		lineLength=rv556;
		} else 
		if (j==557) {
		lineLength=rv557;
		} else 
		if (j==558) {
		lineLength=rv558;
		} else 
		if (j==559) {
		lineLength=rv559;
		} else 
		if (j==560) {
		lineLength=rv560;
		} else 
		if (j==561) {
		lineLength=rv561;
		} else 
		if (j==562) {
		lineLength=rv562;
		} else 
		if (j==563) {
		lineLength=rv563;
		} else 
		if (j==564) {
		lineLength=rv564;
		} else 
		if (j==565) {
		lineLength=rv565;
		} else 
		if (j==566) {
		lineLength=rv566;
		} else 
		if (j==567) {
		lineLength=rv567;
		} else 
		if (j==568) {
		lineLength=rv568;
		} else 
		if (j==569) {
		lineLength=rv569;
		} else 
		if (j==570) {
		lineLength=rv570;
		} else 
		if (j==571) {
		lineLength=rv571;
		} else 
		if (j==572) {
		lineLength=rv572;
		} else 
		if (j==573) {
		lineLength=rv573;
		} else 
		if (j==574) {
		lineLength=rv574;
		} else 
		if (j==575) {
		lineLength=rv575;
		} else 
		if (j==576) {
		lineLength=rv576;
		} else 
		if (j==577) {
		lineLength=rv577;
		} else 
		if (j==578) {
		lineLength=rv578;
		} else 
		if (j==579) {
		lineLength=rv579;
		} else 
		if (j==580) {
		lineLength=rv580;
		} else 
		if (j==581) {
		lineLength=rv581;
		} else 
		if (j==582) {
		lineLength=rv582;
		} else 
		if (j==583) {
		lineLength=rv583;
		} else 
		if (j==584) {
		lineLength=rv584;
		} else 
		if (j==585) {
		lineLength=rv585;
		} else 
		if (j==586) {
		lineLength=rv586;
		} else 
		if (j==587) {
		lineLength=rv587;
		} else 
		if (j==588) {
		lineLength=rv588;
		} else 
		if (j==589) {
		lineLength=rv589;
		} else 
		if (j==590) {
		lineLength=rv590;
		} else 
		if (j==591) {
		lineLength=rv591;
		} else 
		if (j==592) {
		lineLength=rv592;
		} else 
		if (j==593) {
		lineLength=rv593;
		} else 
		if (j==594) {
		lineLength=rv594;
		} else 
		if (j==595) {
		lineLength=rv595;
		} else 
		if (j==596) {
		lineLength=rv596;
		} else 
		if (j==597) {
		lineLength=rv597;
		} else 
		if (j==598) {
		lineLength=rv598;
		} else 
		if (j==599) {
		lineLength=rv599;
		} else 
		if (j==600) {
		lineLength=rv600;
		} else 
		if (j==601) {
		lineLength=rv601;
		} else 
		if (j==602) {
		lineLength=rv602;
		} else 
		if (j==603) {
		lineLength=rv603;
		} else 
		if (j==604) {
		lineLength=rv604;
		} else 
		if (j==605) {
		lineLength=rv605;
		} else 
		if (j==606) {
		lineLength=rv606;
		} else 
		if (j==607) {
		lineLength=rv607;
		} else 
		if (j==608) {
		lineLength=rv608;
		} else 
		if (j==609) {
		lineLength=rv609;
		} else 
		if (j==610) {
		lineLength=rv610;
		} else 
		if (j==611) {
		lineLength=rv611;
		} else 
		if (j==612) {
		lineLength=rv612;
		} else 
		if (j==613) {
		lineLength=rv613;
		} else 
		if (j==614) {
		lineLength=rv614;
		} else 
		if (j==615) {
		lineLength=rv615;
		} else 
		if (j==616) {
		lineLength=rv616;
		} else 
		if (j==617) {
		lineLength=rv617;
		} else 
		if (j==618) {
		lineLength=rv618;
		} else 
		if (j==619) {
		lineLength=rv619;
		} else 
		if (j==620) {
		lineLength=rv620;
		} else 
		if (j==621) {
		lineLength=rv621;
		} else 
		if (j==622) {
		lineLength=rv622;
		} else 
		if (j==623) {
		lineLength=rv623;
		} else 
		if (j==624) {
		lineLength=rv624;
		} else 
		if (j==625) {
		lineLength=rv625;
		} else 
		if (j==626) {
		lineLength=rv626;
		} else 
		if (j==627) {
		lineLength=rv627;
		} else 
		if (j==628) {
		lineLength=rv628;
		} else 
		if (j==629) {
		lineLength=rv629;
		} else 
		if (j==630) {
		lineLength=rv630;
		} else 
		if (j==631) {
		lineLength=rv631;
		} else 
		if (j==632) {
		lineLength=rv632;
		} else 
		if (j==633) {
		lineLength=rv633;
		} else 
		if (j==634) {
		lineLength=rv634;
		} else 
		if (j==635) {
		lineLength=rv635;
		} else 
		if (j==636) {
		lineLength=rv636;
		} else 
		if (j==637) {
		lineLength=rv637;
		} else 
		if (j==638) {
		lineLength=rv638;
		} else 
		if (j==639) {
		lineLength=rv639;
		} else 
		if (j==640) {
		lineLength=rv640;
		} else 
		if (j==641) {
		lineLength=rv641;
		} else 
		if (j==642) {
		lineLength=rv642;
		} else 
		if (j==643) {
		lineLength=rv643;
		} else 
		if (j==644) {
		lineLength=rv644;
		} else 
		if (j==645) {
		lineLength=rv645;
		} else 
		if (j==646) {
		lineLength=rv646;
		} else 
		if (j==647) {
		lineLength=rv647;
		} else 
		if (j==648) {
		lineLength=rv648;
		} else 
		if (j==649) {
		lineLength=rv649;
		} else 
		if (j==650) {
		lineLength=rv650;
		} else 
		if (j==651) {
		lineLength=rv651;
		} else 
		if (j==652) {
		lineLength=rv652;
		} else 
		if (j==653) {
		lineLength=rv653;
		} else 
		if (j==654) {
		lineLength=rv654;
		} else 
		if (j==655) {
		lineLength=rv655;
		} else 
		if (j==656) {
		lineLength=rv656;
		} else 
		if (j==657) {
		lineLength=rv657;
		} else 
		if (j==658) {
		lineLength=rv658;
		} else 
		if (j==659) {
		lineLength=rv659;
		} else 
		if (j==660) {
		lineLength=rv660;
		} else 
		if (j==661) {
		lineLength=rv661;
		} else 
		if (j==662) {
		lineLength=rv662;
		} else 
		if (j==663) {
		lineLength=rv663;
		} else 
		if (j==664) {
		lineLength=rv664;
		} else 
		if (j==665) {
		lineLength=rv665;
		} else 
		if (j==666) {
		lineLength=rv666;
		} else 
		if (j==667) {
		lineLength=rv667;
		} else 
		if (j==668) {
		lineLength=rv668;
		} else 
		if (j==669) {
		lineLength=rv669;
		} else 
		if (j==670) {
		lineLength=rv670;
		} else 
		if (j==671) {
		lineLength=rv671;
		} else 
		if (j==672) {
		lineLength=rv672;
		} else 
		if (j==673) {
		lineLength=rv673;
		} else 
		if (j==674) {
		lineLength=rv674;
		} else 
		if (j==675) {
		lineLength=rv675;
		} else 
		if (j==676) {
		lineLength=rv676;
		} else 
		if (j==677) {
		lineLength=rv677;
		} else 
		if (j==678) {
		lineLength=rv678;
		} else 
		if (j==679) {
		lineLength=rv679;
		} else 
		if (j==680) {
		lineLength=rv680;
		} else 
		if (j==681) {
		lineLength=rv681;
		} else 
		if (j==682) {
		lineLength=rv682;
		} else 
		if (j==683) {
		lineLength=rv683;
		} else 
		if (j==684) {
		lineLength=rv684;
		} else 
		if (j==685) {
		lineLength=rv685;
		} else 
		if (j==686) {
		lineLength=rv686;
		} else 
		if (j==687) {
		lineLength=rv687;
		} else 
		if (j==688) {
		lineLength=rv688;
		} else 
		if (j==689) {
		lineLength=rv689;
		} else 
		if (j==690) {
		lineLength=rv690;
		} else 
		if (j==691) {
		lineLength=rv691;
		} else 
		if (j==692) {
		lineLength=rv692;
		} else 
		if (j==693) {
		lineLength=rv693;
		} else 
		if (j==694) {
		lineLength=rv694;
		} else 
		if (j==695) {
		lineLength=rv695;
		} else 
		if (j==696) {
		lineLength=rv696;
		} else 
		if (j==697) {
		lineLength=rv697;
		} else 
		if (j==698) {
		lineLength=rv698;
		} else 
		if (j==699) {
		lineLength=rv699;
		} else 
		if (j==700) {
		lineLength=rv700;
		} else 
		if (j==701) {
		lineLength=rv701;
		} else 
		if (j==702) {
		lineLength=rv702;
		} else 
		if (j==703) {
		lineLength=rv703;
		} else 
		if (j==704) {
		lineLength=rv704;
		} else 
		if (j==705) {
		lineLength=rv705;
		} else 
		if (j==706) {
		lineLength=rv706;
		} else 
		if (j==707) {
		lineLength=rv707;
		} else 
		if (j==708) {
		lineLength=rv708;
		} else 
		if (j==709) {
		lineLength=rv709;
		} else 
		if (j==710) {
		lineLength=rv710;
		} else 
		if (j==711) {
		lineLength=rv711;
		} else 
		if (j==712) {
		lineLength=rv712;
		} else 
		if (j==713) {
		lineLength=rv713;
		} else 
		if (j==714) {
		lineLength=rv714;
		} else 
		if (j==715) {
		lineLength=rv715;
		} else 
		if (j==716) {
		lineLength=rv716;
		} else 
		if (j==717) {
		lineLength=rv717;
		} else 
		if (j==718) {
		lineLength=rv718;
		} else 
		if (j==719) {
		lineLength=rv719;
		} else 
		if (j==720) {
		lineLength=rv720;
		} else 
		if (j==721) {
		lineLength=rv721;
		} else 
		if (j==722) {
		lineLength=rv722;
		} else 
		if (j==723) {
		lineLength=rv723;
		} else 
		if (j==724) {
		lineLength=rv724;
		} else 
		if (j==725) {
		lineLength=rv725;
		} else 
		if (j==726) {
		lineLength=rv726;
		} else 
		if (j==727) {
		lineLength=rv727;
		} else 
		if (j==728) {
		lineLength=rv728;
		} else 
		if (j==729) {
		lineLength=rv729;
		} else 
		if (j==730) {
		lineLength=rv730;
		} else 
		if (j==731) {
		lineLength=rv731;
		} else 
		if (j==732) {
		lineLength=rv732;
		} else 
		if (j==733) {
		lineLength=rv733;
		} else 
		if (j==734) {
		lineLength=rv734;
		} else 
		if (j==735) {
		lineLength=rv735;
		} else 
		if (j==736) {
		lineLength=rv736;
		} else 
		if (j==737) {
		lineLength=rv737;
		} else 
		if (j==738) {
		lineLength=rv738;
		} else 
		if (j==739) {
		lineLength=rv739;
		} else 
		if (j==740) {
		lineLength=rv740;
		} else 
		if (j==741) {
		lineLength=rv741;
		} else 
		if (j==742) {
		lineLength=rv742;
		} else 
		if (j==743) {
		lineLength=rv743;
		} else 
		if (j==744) {
		lineLength=rv744;
		} else 
		if (j==745) {
		lineLength=rv745;
		} else 
		if (j==746) {
		lineLength=rv746;
		} else 
		if (j==747) {
		lineLength=rv747;
		} else 
		if (j==748) {
		lineLength=rv748;
		} else 
		if (j==749) {
		lineLength=rv749;
		} else 
		if (j==750) {
		lineLength=rv750;
		} else 
		if (j==751) {
		lineLength=rv751;
		} else 
		if (j==752) {
		lineLength=rv752;
		} else 
		if (j==753) {
		lineLength=rv753;
		} else 
		if (j==754) {
		lineLength=rv754;
		} else 
		if (j==755) {
		lineLength=rv755;
		} else 
		if (j==756) {
		lineLength=rv756;
		} else 
		if (j==757) {
		lineLength=rv757;
		} else 
		if (j==758) {
		lineLength=rv758;
		} else 
		if (j==759) {
		lineLength=rv759;
		} else 
		if (j==760) {
		lineLength=rv760;
		} else 
		if (j==761) {
		lineLength=rv761;
		} else 
		if (j==762) {
		lineLength=rv762;
		} else 
		if (j==763) {
		lineLength=rv763;
		} else 
		if (j==764) {
		lineLength=rv764;
		} else 
		if (j==765) {
		lineLength=rv765;
		} else 
		if (j==766) {
		lineLength=rv766;
		} else 
		if (j==767) {
		lineLength=rv767;
		} else 
		if (j==768) {
		lineLength=rv768;
		} else 
		if (j==769) {
		lineLength=rv769;
		} else 
		if (j==770) {
		lineLength=rv770;
		} else 
		if (j==771) {
		lineLength=rv771;
		} else 
		if (j==772) {
		lineLength=rv772;
		} else 
		if (j==773) {
		lineLength=rv773;
		} else 
		if (j==774) {
		lineLength=rv774;
		} else 
		if (j==775) {
		lineLength=rv775;
		} else 
		if (j==776) {
		lineLength=rv776;
		} else 
		if (j==777) {
		lineLength=rv777;
		} else 
		if (j==778) {
		lineLength=rv778;
		} else 
		if (j==779) {
		lineLength=rv779;
		} else 
		if (j==780) {
		lineLength=rv780;
		} else 
		if (j==781) {
		lineLength=rv781;
		} else 
		if (j==782) {
		lineLength=rv782;
		} else 
		if (j==783) {
		lineLength=rv783;
		} else 
		if (j==784) {
		lineLength=rv784;
		} else 
		if (j==785) {
		lineLength=rv785;
		} else 
		if (j==786) {
		lineLength=rv786;
		} else 
		if (j==787) {
		lineLength=rv787;
		} else 
		if (j==788) {
		lineLength=rv788;
		} else 
		if (j==789) {
		lineLength=rv789;
		} else 
		if (j==790) {
		lineLength=rv790;
		} else 
		if (j==791) {
		lineLength=rv791;
		} else 
		if (j==792) {
		lineLength=rv792;
		} else 
		if (j==793) {
		lineLength=rv793;
		} else 
		if (j==794) {
		lineLength=rv794;
		} else 
		if (j==795) {
		lineLength=rv795;
		} else 
		if (j==796) {
		lineLength=rv796;
		} else 
		if (j==797) {
		lineLength=rv797;
		} else 
		if (j==798) {
		lineLength=rv798;
		} else 
		if (j==799) {
		lineLength=rv799;
		} else 
		if (j==800) {
		lineLength=rv800;
		} else 
		if (j==801) {
		lineLength=rv801;
		} else 
		if (j==802) {
		lineLength=rv802;
		} else 
		if (j==803) {
		lineLength=rv803;
		} else 
		if (j==804) {
		lineLength=rv804;
		} else 
		if (j==805) {
		lineLength=rv805;
		} else 
		if (j==806) {
		lineLength=rv806;
		} else 
		if (j==807) {
		lineLength=rv807;
		} else 
		if (j==808) {
		lineLength=rv808;
		} else 
		if (j==809) {
		lineLength=rv809;
		} else 
		if (j==810) {
		lineLength=rv810;
		} else 
		if (j==811) {
		lineLength=rv811;
		} else 
		if (j==812) {
		lineLength=rv812;
		} else 
		if (j==813) {
		lineLength=rv813;
		} else 
		if (j==814) {
		lineLength=rv814;
		} else 
		if (j==815) {
		lineLength=rv815;
		} else 
		if (j==816) {
		lineLength=rv816;
		} else 
		if (j==817) {
		lineLength=rv817;
		} else 
		if (j==818) {
		lineLength=rv818;
		} else 
		if (j==819) {
		lineLength=rv819;
		} else 
		if (j==820) {
		lineLength=rv820;
		} else 
		if (j==821) {
		lineLength=rv821;
		} else 
		if (j==822) {
		lineLength=rv822;
		} else 
		if (j==823) {
		lineLength=rv823;
		} else 
		if (j==824) {
		lineLength=rv824;
		} else 
		if (j==825) {
		lineLength=rv825;
		} else 
		if (j==826) {
		lineLength=rv826;
		} else 
		if (j==827) {
		lineLength=rv827;
		} else 
		if (j==828) {
		lineLength=rv828;
		} else 
		if (j==829) {
		lineLength=rv829;
		} else 
		if (j==830) {
		lineLength=rv830;
		} else 
		if (j==831) {
		lineLength=rv831;
		} else 
		if (j==832) {
		lineLength=rv832;
		} else 
		if (j==833) {
		lineLength=rv833;
		} else 
		if (j==834) {
		lineLength=rv834;
		} else 
		if (j==835) {
		lineLength=rv835;
		} else 
		if (j==836) {
		lineLength=rv836;
		} else 
		if (j==837) {
		lineLength=rv837;
		} else 
		if (j==838) {
		lineLength=rv838;
		} else 
		if (j==839) {
		lineLength=rv839;
		} else 
		if (j==840) {
		lineLength=rv840;
		} else 
		if (j==841) {
		lineLength=rv841;
		} else 
		if (j==842) {
		lineLength=rv842;
		} else 
		if (j==843) {
		lineLength=rv843;
		} else 
		if (j==844) {
		lineLength=rv844;
		} else 
		if (j==845) {
		lineLength=rv845;
		} else 
		if (j==846) {
		lineLength=rv846;
		} else 
		if (j==847) {
		lineLength=rv847;
		} else 
		if (j==848) {
		lineLength=rv848;
		} else 
		if (j==849) {
		lineLength=rv849;
		} else 
		if (j==850) {
		lineLength=rv850;
		} else 
		if (j==851) {
		lineLength=rv851;
		} else 
		if (j==852) {
		lineLength=rv852;
		} else 
		if (j==853) {
		lineLength=rv853;
		} else 
		if (j==854) {
		lineLength=rv854;
		} else 
		if (j==855) {
		lineLength=rv855;
		} else 
		if (j==856) {
		lineLength=rv856;
		} else 
		if (j==857) {
		lineLength=rv857;
		} else 
		if (j==858) {
		lineLength=rv858;
		} else 
		if (j==859) {
		lineLength=rv859;
		} else 
		if (j==860) {
		lineLength=rv860;
		} else 
		if (j==861) {
		lineLength=rv861;
		} else 
		if (j==862) {
		lineLength=rv862;
		} else 
		if (j==863) {
		lineLength=rv863;
		} else 
		if (j==864) {
		lineLength=rv864;
		} else 
		if (j==865) {
		lineLength=rv865;
		} else 
		if (j==866) {
		lineLength=rv866;
		} else 
		if (j==867) {
		lineLength=rv867;
		} else 
		if (j==868) {
		lineLength=rv868;
		} else 
		if (j==869) {
		lineLength=rv869;
		} else 
		if (j==870) {
		lineLength=rv870;
		} else 
		if (j==871) {
		lineLength=rv871;
		} else 
		if (j==872) {
		lineLength=rv872;
		} else 
		if (j==873) {
		lineLength=rv873;
		} else 
		if (j==874) {
		lineLength=rv874;
		} else 
		if (j==875) {
		lineLength=rv875;
		} else 
		if (j==876) {
		lineLength=rv876;
		} else 
		if (j==877) {
		lineLength=rv877;
		} else 
		if (j==878) {
		lineLength=rv878;
		} else 
		if (j==879) {
		lineLength=rv879;
		} else 
		if (j==880) {
		lineLength=rv880;
		} else 
		if (j==881) {
		lineLength=rv881;
		} else 
		if (j==882) {
		lineLength=rv882;
		} else 
		if (j==883) {
		lineLength=rv883;
		} else 
		if (j==884) {
		lineLength=rv884;
		} else 
		if (j==885) {
		lineLength=rv885;
		} else 
		if (j==886) {
		lineLength=rv886;
		} else 
		if (j==887) {
		lineLength=rv887;
		} else 
		if (j==888) {
		lineLength=rv888;
		} else 
		if (j==889) {
		lineLength=rv889;
		} else 
		if (j==890) {
		lineLength=rv890;
		} else 
		if (j==891) {
		lineLength=rv891;
		} else 
		if (j==892) {
		lineLength=rv892;
		} else 
		if (j==893) {
		lineLength=rv893;
		} else 
		if (j==894) {
		lineLength=rv894;
		} else 
		if (j==895) {
		lineLength=rv895;
		} else 
		if (j==896) {
		lineLength=rv896;
		} else 
		if (j==897) {
		lineLength=rv897;
		} else 
		if (j==898) {
		lineLength=rv898;
		} else 
		if (j==899) {
		lineLength=rv899;
		} else 
		if (j==900) {
		lineLength=rv900;
		} else 
		if (j==901) {
		lineLength=rv901;
		} else 
		if (j==902) {
		lineLength=rv902;
		} else 
		if (j==903) {
		lineLength=rv903;
		} else 
		if (j==904) {
		lineLength=rv904;
		} else 
		if (j==905) {
		lineLength=rv905;
		} else 
		if (j==906) {
		lineLength=rv906;
		} else 
		if (j==907) {
		lineLength=rv907;
		} else 
		if (j==908) {
		lineLength=rv908;
		} else 
		if (j==909) {
		lineLength=rv909;
		} else 
		if (j==910) {
		lineLength=rv910;
		} else 
		if (j==911) {
		lineLength=rv911;
		} else 
		if (j==912) {
		lineLength=rv912;
		} else 
		if (j==913) {
		lineLength=rv913;
		} else 
		if (j==914) {
		lineLength=rv914;
		} else 
		if (j==915) {
		lineLength=rv915;
		} else 
		if (j==916) {
		lineLength=rv916;
		} else 
		if (j==917) {
		lineLength=rv917;
		} else 
		if (j==918) {
		lineLength=rv918;
		} else 
		if (j==919) {
		lineLength=rv919;
		} else 
		if (j==920) {
		lineLength=rv920;
		} else 
		if (j==921) {
		lineLength=rv921;
		} else 
		if (j==922) {
		lineLength=rv922;
		} else 
		if (j==923) {
		lineLength=rv923;
		} else 
		if (j==924) {
		lineLength=rv924;
		} else 
		if (j==925) {
		lineLength=rv925;
		} else 
		if (j==926) {
		lineLength=rv926;
		} else 
		if (j==927) {
		lineLength=rv927;
		} else 
		if (j==928) {
		lineLength=rv928;
		} else 
		if (j==929) {
		lineLength=rv929;
		} else 
		if (j==930) {
		lineLength=rv930;
		} else 
		if (j==931) {
		lineLength=rv931;
		} else 
		if (j==932) {
		lineLength=rv932;
		} else 
		if (j==933) {
		lineLength=rv933;
		} else 
		if (j==934) {
		lineLength=rv934;
		} else 
		if (j==935) {
		lineLength=rv935;
		} else 
		if (j==936) {
		lineLength=rv936;
		} else 
		if (j==937) {
		lineLength=rv937;
		} else 
		if (j==938) {
		lineLength=rv938;
		} else 
		if (j==939) {
		lineLength=rv939;
		} else 
		if (j==940) {
		lineLength=rv940;
		} else 
		if (j==941) {
		lineLength=rv941;
		} else 
		if (j==942) {
		lineLength=rv942;
		} else 
		if (j==943) {
		lineLength=rv943;
		} else 
		if (j==944) {
		lineLength=rv944;
		} else 
		if (j==945) {
		lineLength=rv945;
		} else 
		if (j==946) {
		lineLength=rv946;
		} else 
		if (j==947) {
		lineLength=rv947;
		} else 
		if (j==948) {
		lineLength=rv948;
		} else 
		if (j==949) {
		lineLength=rv949;
		} else 
		if (j==950) {
		lineLength=rv950;
		} else 
		if (j==951) {
		lineLength=rv951;
		} else 
		if (j==952) {
		lineLength=rv952;
		} else 
		if (j==953) {
		lineLength=rv953;
		} else 
		if (j==954) {
		lineLength=rv954;
		} else 
		if (j==955) {
		lineLength=rv955;
		} else 
		if (j==956) {
		lineLength=rv956;
		} else 
		if (j==957) {
		lineLength=rv957;
		} else 
		if (j==958) {
		lineLength=rv958;
		} else 
		if (j==959) {
		lineLength=rv959;
		} else 
		if (j==960) {
		lineLength=rv960;
		} else 
		if (j==961) {
		lineLength=rv961;
		} else 
		if (j==962) {
		lineLength=rv962;
		} else 
		if (j==963) {
		lineLength=rv963;
		} else 
		if (j==964) {
		lineLength=rv964;
		} else 
		if (j==965) {
		lineLength=rv965;
		} else 
		if (j==966) {
		lineLength=rv966;
		} else 
		if (j==967) {
		lineLength=rv967;
		} else 
		if (j==968) {
		lineLength=rv968;
		} else 
		if (j==969) {
		lineLength=rv969;
		} else 
		if (j==970) {
		lineLength=rv970;
		} else 
		if (j==971) {
		lineLength=rv971;
		} else 
		if (j==972) {
		lineLength=rv972;
		} else 
		if (j==973) {
		lineLength=rv973;
		} else 
		if (j==974) {
		lineLength=rv974;
		} else 
		if (j==975) {
		lineLength=rv975;
		} else 
		if (j==976) {
		lineLength=rv976;
		} else 
		if (j==977) {
		lineLength=rv977;
		} else 
		if (j==978) {
		lineLength=rv978;
		} else 
		if (j==979) {
		lineLength=rv979;
		} else 
		if (j==980) {
		lineLength=rv980;
		} else 
		if (j==981) {
		lineLength=rv981;
		} else 
		if (j==982) {
		lineLength=rv982;
		} else 
		if (j==983) {
		lineLength=rv983;
		} else 
		if (j==984) {
		lineLength=rv984;
		} else 
		if (j==985) {
		lineLength=rv985;
		} else 
		if (j==986) {
		lineLength=rv986;
		} else 
		if (j==987) {
		lineLength=rv987;
		} else 
		if (j==988) {
		lineLength=rv988;
		} else 
		if (j==989) {
		lineLength=rv989;
		} else 
		if (j==990) {
		lineLength=rv990;
		} else 
		if (j==991) {
		lineLength=rv991;
		} else 
		if (j==992) {
		lineLength=rv992;
		} else 
		if (j==993) {
		lineLength=rv993;
		} else 
		if (j==994) {
		lineLength=rv994;
		} else 
		if (j==995) {
		lineLength=rv995;
		} else 
		if (j==996) {
		lineLength=rv996;
		} else 
		if (j==997) {
		lineLength=rv997;
		} else 
		if (j==998) {
		lineLength=rv998;
		} else 
		if (j==999) {
		lineLength=rv999;
		} 
		for (int k=0; k<lineLength; ++k) {
			// Generate a random number from 0-3
			int v1 = rand() % 4;
			if (v1==0) {
				if (a>=1) {
					a--;
					o<<'A';
				} else if (c>=1) {
					c--;
					o<<'C';
				} else if (t>=1) {
					t--;
					o<<'T';
				} else if (g>=1) {
					g--;
					o<<'G';
				}
			} else if (v1==1) {
				if (c>=1) {
					c--;
					o<<'C';
				} else if (a>=1) {
					a--;
					o<<'A';
				} else if (t>=1) {
					t--;
					o<<'T';
				} else if (g>=1) {
					g--;
					o<<'G';
				}
			} else if (v1==2) {
				if (t>=1) {
					t--;
					o<<'T';
				} else if (c>=1) {
					c--;
					o<<'C';
				} else if (a>=1) {
					a--;
					o<<'A';
				} else if (g>=1) {
					g--;
					o<<'G';
				}
			} else if (v1==3) {
				if (g>=1) {
					g--;
					o<<'G';
				} else if (c>=1) {
					c--;
					o<<'C';
				} else if (t>=1) {
					t--;
					o<<'T';
				} else if (a>=1) {
					a--;
					o<<'A';
				}
			}
		}
		o<<"\n";
	}
	o<<"---END---\n";
	o.close();
}
