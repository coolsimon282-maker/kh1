# Hard functions still to crack (Final Mix)

Snapshot of `fm` on 25 Nov 2026: every game function in the **hard** tier that is still `INCLUDE_ASM`. **308 hard functions, 272,336 bytes**, in 48 files. A further 242 functions are **parked** (vector-unit code, jump tables, traps: set aside by the tier rules) and are listed at the end.

Tiers come from `eu-notes/tiers.py` (size, branches, calls, float and 64-bit work, earlier give-ups). The score is its difficulty estimate: higher is harder. "Notes" names the `notes/*.md` files that mention the function: read those first, they usually say exactly what was off.

## Matches set aside in merges (redo first)

These match on their own branch, but combined with other workers' matches in the same file they moved other functions (rule F1), so `fm` keeps the file without them. Each needs an F1 pad/layout fix (notes/a1.md N4/N7, notes/a4.md F24, notes/a5.md on pad name length). The C is on the named branch.

| File | Functions | Branch |
|---|---|---|
| `unsplit/seg_0EF950` | `func_0020E1C0`, `func_001F81E8` | fm-q1 |
| `unsplit/seg_11AC38` | `func_0021D948`, `func_002204F0`, `func_00225C30`, `func_00230728` | fm-q1 |
| `unsplit/seg_132D60` | `func_0023A608` | fm-a4 |
| `unsplit/seg_03BDE8` | `func_00147D50`, `func_00149BD0`, `func_0014F868`, `func_00152688`, `func_001590A8`, `func_00159350`, `func_00162428` | fm-q1 |

## By file

| File | Hard left | Bytes | Already attempted |
|---|---:|---:|---:|
| `unsplit/seg_03BDE8` | 61 | 60,988 | 18 |
| `unsplit/seg_0EF950` | 41 | 57,380 | 17 |
| `xhumungus` | 21 | 16,124 | 5 |
| `unsplit/seg_0DDC78` | 19 | 12,468 | 13 |
| `unsplit/seg_11AC38` | 16 | 16,272 | 12 |
| `unsplit/seg_132D60` | 16 | 16,824 | 7 |
| `xpotato` | 14 | 8,784 | 10 |
| `xsauce` | 10 | 4,004 | 9 |
| `unsplit/seg_02B2C0` | 10 | 9,124 | 3 |
| `xflamingo` | 9 | 8,672 | 5 |
| `unsplit/seg_14B9A8` | 9 | 4,116 | 6 |
| `xtailor` | 6 | 2,784 | 5 |
| `unsplit/seg_001970` | 6 | 5,880 | 3 |
| `unsplit/seg_0B9B78` | 6 | 3,776 | 4 |
| `xbeginning` | 5 | 1,484 | 5 |
| `unsplit/seg_0C45E8` | 5 | 5,484 | 2 |
| `xapple` | 4 | 1,196 | 4 |
| `xarcade` | 4 | 1,164 | 4 |
| `ppp/pppMngr` | 4 | 2,732 | 4 |
| `unsplit/seg_0150D8` | 4 | 2,748 | 1 |
| `xcream` | 3 | 3,532 | 1 |
| `ppp/draw/draw` | 3 | 3,136 | 2 |
| `ppp/ryjProg/pppRyjDrawMatrixWorldDttFr` | 3 | 1,916 | 3 |
| `xblade` | 2 | 1,256 | 2 |
| `xnoodle` | 2 | 1,800 | 2 |
| `ppp/ryjProg/pppRyjMegaPlace` | 2 | 1,836 | 0 |
| `unsplit/seg_0252F8` | 2 | 2,956 | 0 |
| `xgoblin` | 1 | 72 | 1 |
| `unsplit/seg_01FD30` | 1 | 136 | 1 |
| `xowl` | 1 | 592 | 1 |
| `xpackage` | 1 | 436 | 1 |
| `xpeanut` | 1 | 180 | 1 |
| `xporcupine` | 1 | 712 | 1 |
| `xtoaster` | 1 | 1,484 | 1 |
| `xtrumpet` | 1 | 176 | 1 |
| `ppp/xberry` | 1 | 740 | 1 |
| `ppp/eiProg/pppDrawMdlTs` | 1 | 388 | 1 |
| `ppp/eiProg/pppDrawShape` | 1 | 260 | 1 |
| `ppp/keProg/pppKeBornRnd` | 1 | 828 | 1 |
| `ppp/keProg/pppKeBornRnd4` | 1 | 964 | 1 |
| `ppp/keProg/pppKeShpTail3` | 1 | 992 | 1 |
| `ppp/keProg/pppKeTh` | 1 | 140 | 1 |
| `ppp/keProg/pppKeThHitBorn` | 1 | 512 | 1 |
| `ppp/ryjProg/pppRyjMegaBirthFilter` | 1 | 2,312 | 1 |
| `ppp/ryjProg/pppRyjMegaBirthModel` | 1 | 1,072 | 0 |
| `unsplit/seg_006B18` | 1 | 1,388 | 0 |
| `unsplit/seg_01C7A8` | 1 | 164 | 1 |
| `unsplit/seg_0EDC50` | 1 | 352 | 1 |

## `unsplit/seg_03BDE8` (61)

| Function | Bytes | Score | Notes |
|---|---:|---:|---|
| `func_00171078` | 28 | 8 | a1, a2, a3, f1, q1 |
| `func_001713F8` | 100 | 38 | a1, a2, a3 |
| `func_00152880` | 112 | 38.5 | a6, f1, fable |
| `func_00177908` | 152 | 67 | a1, a3, a6 |
| `func_0015F018` | 236 | 72 | a1, a6, f1 |
| `func_00152770` | 272 | 97 | a1, f1, fable |
| `func_00157A30` | 560 | 205.5 | a1, f1 |
| `func_0017DF08` | 616 | 221.5 | a1, f1 |
| `func_0017F688` | 596 | 228 | a1, f1 |
| `func_00143818` | 596 | 230 | a1 |
| `func_00152928` | 640 | 234 | a1 |
| `func_0017CF08` | 724 | 247.5 | a1 |
| `func_0017AE48` | 660 | 251 | a1 |
| `func_00141B10` | 852 | 275 | a2, a5 |
| `func_0015E178` | 704 | 275.5 |  |
| `func_00159F78` | 732 | 279 |  |
| `func_001581D8` | 740 | 284.5 |  |
| `func_00168D20` | 744 | 288.5 |  |
| `func_00145528` | 812 | 290.5 |  |
| `func_00174FC0` | 736 | 291 | a1 |
| `func_00163150` | 832 | 291 |  |
| `func_00166248` | 808 | 298 |  |
| `func_0014B090` | 844 | 298.5 |  |
| `func_001752A0` | 860 | 298.5 |  |
| `func_0017BC90` | 856 | 307.5 |  |
| `func_0017E428` | 828 | 315.5 | a1 |
| `func_0014FE48` | 884 | 317.5 |  |
| `func_00160370` | 860 | 321 |  |
| `func_001568E8` | 812 | 322 |  |
| `func_0014BDC0` | 880 | 323.5 |  |
| `func_001480D0` | 872 | 324 |  |
| `func_0017CB88` | 892 | 338 | a1 |
| `func_001502E8` | 888 | 345 |  |
| `func_00144958` | 904 | 355.5 |  |
| `func_0017D628` | 928 | 369 |  |
| `func_00161A08` | 988 | 369 |  |
| `func_001784C8` | 968 | 383.5 |  |
| `func_00177AC0` | 1076 | 394.5 |  |
| `func_00164768` | 1084 | 402.5 |  |
| `func_0016FD98` | 980 | 408.5 |  |
| `func_00162D00` | 1100 | 408.5 |  |
| `func_0016D768` | 1044 | 414 |  |
| `func_0017A958` | 1180 | 441.5 |  |
| `func_0016BB68` | 1152 | 465 |  |
| `func_0016BFE8` | 1176 | 473 |  |
| `func_0016B1F0` | 1148 | 474.5 |  |
| `func_0016D2D0` | 1176 | 502 |  |
| `func_0016B670` | 1268 | 506.5 | a1 |
| `func_00177EF8` | 1388 | 506.5 |  |
| `func_00165CF8` | 1360 | 509 |  |
| `func_0015CC48` | 1412 | 537.5 |  |
| `func_001707D0` | 1420 | 549.5 |  |
| `func_00164F18` | 1332 | 569 |  |
| `func_0016C650` | 1348 | 596 |  |
| `func_00179EE8` | 1576 | 598 |  |
| `func_0016E3F8` | 1628 | 632.5 |  |
| `func_0016ABC0` | 1580 | 669.5 |  |
| `func_00178EF8` | 1940 | 744.5 |  |
| `func_0016EA58` | 1940 | 787.5 |  |
| `func_0016A3F8` | 1988 | 823 |  |
| `func_00166570` | 4176 | 1467 |  |

## `unsplit/seg_0EF950` (41)

| Function | Bytes | Score | Notes |
|---|---:|---:|---|
| `func_0020A248` | 720 | 257.5 | a2 |
| `func_001F12C0` | 812 | 261 | a2 |
| `func_00202300` | 888 | 265 |  |
| `func_00201F38` | 968 | 282 |  |
| `func_002123B8` | 940 | 285 | a2 |
| `func_001FC330` | 1052 | 309 |  |
| `func_00206748` | 1064 | 311 |  |
| `func_00204948` | 1076 | 322 |  |
| `func_00214FC8` | 912 | 335 | a2, f1 |
| `func_001F5988` | 1160 | 335 |  |
| `func_001F0EA8` | 1048 | 336 |  |
| `func_001FFB30` | 1288 | 336 | f1 |
| `func_001F54F8` | 1164 | 337 |  |
| `func_00211ED0` | 924 | 338 | a2 |
| `func_001FEFF0` | 1176 | 349 |  |
| `func_001FA8B0` | 1064 | 354 |  |
| `func_001F2630` | 1056 | 358 |  |
| `func_001FEA38` | 1288 | 378.5 |  |
| `func_00214B20` | 1072 | 388 | f1 |
| `func_00200E28` | 1556 | 410 | f1 |
| `func_001F4778` | 1428 | 413 |  |
| `func_001F4D10` | 1428 | 413 |  |
| `func_001F9E48` | 1228 | 418 |  |
| `func_001F18E8` | 1288 | 424 | a2 |
| `func_00200038` | 1548 | 448 |  |
| `func_001FF488` | 1640 | 449 | f1 |
| `func_00204D80` | 1640 | 468 |  |
| `func_00212CC0` | 1316 | 484 | f1 |
| `func_00203A10` | 1680 | 490.5 |  |
| `func_0020E588` | 1432 | 525 | f1 |
| `func_001FBCD8` | 1580 | 534 |  |
| `func_0020EC50` | 1552 | 540 | f1 |
| `func_00200648` | 2012 | 545 |  |
| `func_001FB428` | 1832 | 605 | a4, a5 |
| `func_0020F530` | 1712 | 614 | f1 |
| `func_002040F8` | 2128 | 641.5 |  |
| `func_0020FF80` | 1844 | 673 | f1 |
| `func_002134C8` | 1944 | 695 | f1 |
| `func_001FD858` | 1908 | 713.5 |  |
| `func_00208458` | 2636 | 764.5 |  |
| `func_00202678` | 2376 | 800 |  |

## `xhumungus` (21)

| Function | Bytes | Score | Notes |
|---|---:|---:|---|
| `func_001CCEF8` | 128 | 32 | a1, a4, f2 |
| `func_001D11C0` | 120 | 38 | a1, f1 |
| `func_001D0DE0` | 148 | 52 | a1, f1 |
| `func_001D0E78` | 148 | 52 | a1, f1 |
| `func_001C9FE0` | 180 | 55.5 | a2 |
| `func_001CCF78` | 756 | 248 |  |
| `func_001CED38` | 808 | 254 |  |
| `func_001D60A8` | 816 | 258.5 |  |
| `func_001D90B0` | 752 | 260 |  |
| `func_001D46F0` | 876 | 274 |  |
| `func_001D93B8` | 880 | 277.5 |  |
| `func_001D7358` | 896 | 278.5 |  |
| `func_001CB1A8` | 744 | 279.5 |  |
| `func_001CADE0` | 752 | 281.5 |  |
| `func_001DDCE8` | 664 | 293 |  |
| `func_001CA908` | 968 | 339.5 |  |
| `func_001C8470` | 1244 | 347.5 |  |
| `func_001C8950` | 1300 | 366.5 |  |
| `func_001C8E68` | 1300 | 366.5 |  |
| `func_001C9380` | 1356 | 385.5 |  |
| `func_001D9720` | 1288 | 511 |  |

## `unsplit/seg_0DDC78` (19)

| Function | Bytes | Score | Notes |
|---|---:|---:|---|
| `func_001DDFB8` | 120 | 17.3 | a2, a4, f2 |
| `fm_func_001DE0B0` | 124 | 20.4 | a2, f2 |
| `func_001DE030` | 124 | 20.4 | a2, f2 |
| `func_001EA5F8` | 96 | 27 | a2, f2 |
| `func_001EA658` | 96 | 27 | a2, f2 |
| `func_001EC6F8` | 92 | 29 | a2, a4, f2 |
| `func_001EC758` | 104 | 31 | a2, f2 |
| `func_001DF9C0` | 116 | 36 | a2 |
| `func_001E0528` | 128 | 36 | a2, a4 |
| `func_001E0D98` | 752 | 231.5 | a2, a3 |
| `func_001E10F8` | 752 | 231.5 | a2, a3 |
| `func_001EBEB0` | 776 | 234 | a2, a3 |
| `func_001E1838` | 960 | 284.5 |  |
| `func_001E86A0` | 844 | 306 | a4 |
| `func_001E4D50` | 1096 | 363 |  |
| `func_001E58C0` | 1208 | 439 |  |
| `func_001E65D0` | 1436 | 483 |  |
| `func_001E5198` | 1516 | 528 |  |
| `func_001E1C20` | 2128 | 572 |  |

## `unsplit/seg_11AC38` (16)

| Function | Bytes | Score | Notes |
|---|---:|---:|---|
| `func_0021B1B0` | 156 | 56 | a1, a3 |
| `func_0022DB98` | 692 | 250 | f1 |
| `func_0021B860` | 892 | 257 | a3, f1 |
| `func_0021BBE0` | 900 | 261 | f1 |
| `func_0022D730` | 732 | 266 | f1 |
| `func_0022DFD8` | 740 | 270 | f1 |
| `func_0021E120` | 1000 | 289 |  |
| `func_00223A90` | 772 | 301 | a3, f1 |
| `func_00220C28` | 960 | 333 |  |
| `func_0021BF68` | 1256 | 388.5 |  |
| `func_0021E8D8` | 1136 | 401.5 | f1 |
| `func_0021ED60` | 1300 | 456 | f1 |
| `func_00224060` | 1352 | 504 | f1 |
| `func_0022E460` | 1572 | 540 |  |
| `func_0021DC40` | 1248 | 544 | f1 |
| `func_002287F8` | 1564 | 587 | f1 |

## `unsplit/seg_132D60` (16)

| Function | Bytes | Score | Notes |
|---|---:|---:|---|
| `func_00240910` | 104 | 37 | a2, a3, f1, q1 |
| `func_00243EF8` | 652 | 243.5 | a3, f1 |
| `func_00248B58` | 724 | 253.5 | a3, a4, f1 |
| `func_002416A8` | 668 | 267.5 | a3 |
| `func_00246750` | 780 | 284 |  |
| `func_002436C0` | 860 | 305 | a4 |
| `func_0023E8F0` | 916 | 324 | a4 |
| `func_0023DA08` | 828 | 334.5 |  |
| `func_00240400` | 940 | 360 |  |
| `func_0023F250` | 1076 | 388.5 |  |
| `func_00239E30` | 1256 | 437.5 |  |
| `func_00240B68` | 1080 | 439.5 |  |
| `func_0023B570` | 1572 | 449 | f1 |
| `func_0023BB98` | 1560 | 525.5 |  |
| `func_0023AED0` | 1512 | 557 |  |
| `func_00238A70` | 2296 | 751 |  |

## `xpotato` (14)

| Function | Bytes | Score | Notes |
|---|---:|---:|---|
| `func_002192D8` | 396 | 29.8 | a3 |
| `func_00215AF0` | 152 | 52 | a3 |
| `func_00215B88` | 188 | 62 | a3 |
| `func_00218870` | 352 | 116 | a3 |
| `func_002167A0` | 340 | 123 | a3 |
| `func_002186B8` | 388 | 144 | a3 |
| `func_00217908` | 500 | 156 | a3 |
| `func_00215CE8` | 508 | 185 | a3, fable |
| `func_00218DD0` | 728 | 215 | a3, f1 |
| `func_00216D88` | 700 | 233 | a3 |
| `func_002170B0` | 876 | 315 |  |
| `func_00217420` | 1004 | 363 |  |
| `func_002168F8` | 1168 | 393 |  |
| `func_00216198` | 1484 | 522 |  |

## `xsauce` (10)

| Function | Bytes | Score | Notes |
|---|---:|---:|---|
| `func_0010EDC0` | 260 | 78 | a4, a6 |
| `func_0010E8A0` | 260 | 80.5 | a2, a4, a6 |
| `func_0010EA38` | 276 | 98 | a3 |
| `func_0010C918` | 276 | 100 | a3 |
| `func_0010E330` | 284 | 107 | a6 |
| `func_0010EF00` | 388 | 122 | a6 |
| `func_0010E450` | 316 | 125 | a6 |
| `func_0010F1C8` | 440 | 156 | a6 |
| `func_0010CCF0` | 388 | 159.5 | a6 |
| `func_0010C4B8` | 1116 | 321 |  |

## `unsplit/seg_02B2C0` (10)

| Function | Bytes | Score | Notes |
|---|---:|---:|---|
| `func_001337E0` | 80 | 31 | a1, a2, a3, a5 |
| `func_0012D468` | 600 | 222.5 |  |
| `func_001395D8` | 612 | 228 | a3 |
| `func_0012E1B0` | 768 | 282 | a3 |
| `func_001350D8` | 988 | 341 |  |
| `func_00134BA8` | 984 | 355.5 |  |
| `func_00135ED0` | 1364 | 421 |  |
| `func_0012E4B0` | 1216 | 445 |  |
| `func_00136D38` | 1204 | 470 |  |
| `func_00130F18` | 1308 | 491 |  |

## `xflamingo` (9)

| Function | Bytes | Score | Notes |
|---|---:|---:|---|
| `func_001C4598` | 208 | 96 | a3 |
| `func_001C4668` | 212 | 101 | a2, a3 |
| `func_001C3780` | 300 | 136 | a2, a3 |
| `func_001C4FF0` | 928 | 300 | a1, a3 |
| `func_001C4C80` | 868 | 323.5 |  |
| `func_001C5918` | 1104 | 352 |  |
| `func_001C4740` | 1344 | 427 | a1 |
| `func_001C5390` | 1672 | 659 |  |
| `func_001C38E0` | 2036 | 761.5 |  |

## `unsplit/seg_14B9A8` (9)

| Function | Bytes | Score | Notes |
|---|---:|---:|---|
| `func_0024E6E0` | 8 | 2 | a1, a2, q1 |
| `func_0024EBF8` | 36 | 13 | a1, a2, q1 |
| `func_0024EDC8` | 36 | 14 | a1, a2, q1 |
| `func_0024E640` | 56 | 16 | a1, a2, q1 |
| `func_0024E678` | 88 | 24 | a1, a2 |
| `func_0024E6E8` | 116 | 38 | a2 |
| `func_0024C460` | 1112 | 331 |  |
| `func_0024C950` | 1172 | 374 |  |
| `func_0024BE88` | 1492 | 554 |  |

## `xtailor` (6)

| Function | Bytes | Score | Notes |
|---|---:|---:|---|
| `func_00110190` | 168 | 24.9 | a3 |
| `func_00110FC8` | 136 | 44 | a3 |
| `func_00110AE0` | 344 | 122 | a2, a3 |
| `func_00110C70` | 352 | 130.5 | a3 |
| `func_0010F768` | 712 | 246 | a2 |
| `func_00110410` | 1072 | 351.5 |  |

## `unsplit/seg_001970` (6)

| Function | Bytes | Score | Notes |
|---|---:|---:|---|
| `func_00104A90` | 80 | 20 | a1, a2, a3, a6 |
| `func_00102D20` | 136 | 41.5 | a2, a6 |
| `func_00101BB8` | 692 | 231 | a2 |
| `func_001032B0` | 1332 | 470 |  |
| `func_00103C48` | 1496 | 509.5 |  |
| `func_00102118` | 2144 | 664 |  |

## `unsplit/seg_0B9B78` (6)

| Function | Bytes | Score | Notes |
|---|---:|---:|---|
| `func_001BA488` | 28 | 8 | a2, a3, q1 |
| `func_001BB6D0` | 80 | 20 | a2, a3, a4 |
| `func_001BA060` | 168 | 57 | a1, a3 |
| `func_001BD090` | 988 | 375 | a4 |
| `func_001BBF88` | 1308 | 430 |  |
| `func_001BDB58` | 1204 | 445 |  |

## `xbeginning` (5)

| Function | Bytes | Score | Notes |
|---|---:|---:|---|
| `func_001006F8` | 192 | 63.5 | a3 |
| `func_00100E70` | 212 | 74 | a3, a6 |
| `func_00100240` | 232 | 75 | a6 |
| `func_00100B30` | 228 | 80 | a3 |
| `func_00100F48` | 620 | 239 | a3 |

## `unsplit/seg_0C45E8` (5)

| Function | Bytes | Score | Notes |
|---|---:|---:|---|
| `func_001C4ED0` | 664 | 239 | a3 |
| `func_001C5EE8` | 952 | 264 |  |
| `func_001C6A20` | 740 | 281 | a1, a3 |
| `func_001C62A0` | 1148 | 326 |  |
| `func_001C53C8` | 1980 | 719 |  |

## `xapple` (4)

| Function | Bytes | Score | Notes |
|---|---:|---:|---|
| `func_0013B480` | 236 | 82 | a3 |
| `func_0013B9B8` | 264 | 93 | a3 |
| `func_0013AFE8` | 336 | 111 | a3 |
| `func_0013B578` | 360 | 127.5 | a3 |

## `xarcade` (4)

| Function | Bytes | Score | Notes |
|---|---:|---:|---|
| `func_00109F60` | 216 | 73 | a1, a6 |
| `func_001091D8` | 360 | 92 | a1, a2, a6 |
| `func_00109B28` | 292 | 95.5 | a1, a6 |
| `func_00109E30` | 296 | 96.5 | a1, a6 |

## `ppp/pppMngr` (4)

| Function | Bytes | Score | Notes |
|---|---:|---:|---|
| `func_00184298` | 328 | 108 | a3 |
| `func_00182B18` | 340 | 121 | a3 |
| `func_00182D90` | 1012 | 409.5 | a3 |
| `func_001831A0` | 1052 | 421 | a3 |

## `unsplit/seg_0150D8` (4)

| Function | Bytes | Score | Notes |
|---|---:|---:|---|
| `func_00117948` | 612 | 240 | a1, a3 |
| `func_00117DB0` | 684 | 281.5 |  |
| `func_00118868` | 752 | 282.5 |  |
| `func_00116368` | 700 | 286.5 |  |

## `xcream` (3)

| Function | Bytes | Score | Notes |
|---|---:|---:|---|
| `func_00128780` | 996 | 304 | a2 |
| `func_00127560` | 1012 | 323 |  |
| `func_00127C20` | 1524 | 564.5 |  |

## `ppp/draw/draw` (3)

| Function | Bytes | Score | Notes |
|---|---:|---:|---|
| `func_001A95B8` | 104 | 30 | a2, a4, f1 |
| `func_001A9620` | 172 | 53 | a2, f1 |
| `func_001A9C50` | 2860 | 1033.5 |  |

## `ppp/ryjProg/pppRyjDrawMatrixWorldDttFr` (3)

| Function | Bytes | Score | Notes |
|---|---:|---:|---|
| `pppRyjDrawMatrixWorldDttFrCalc` | 232 | 20.2 | a3 |
| `func_001A4BC8` | 492 | 170 | a3 |
| `func_001A4070` | 1192 | 461.5 | a3 |

## `xblade` (2)

| Function | Bytes | Score | Notes |
|---|---:|---:|---|
| `func_00113410` | 516 | 158 | a2, a5 |
| `func_00113710` | 740 | 235 | a2, a5 |

## `xnoodle` (2)

| Function | Bytes | Score | Notes |
|---|---:|---:|---|
| `func_0010B0D0` | 816 | 299 | a5 |
| `func_0010B428` | 984 | 371.5 | a5 |

## `ppp/ryjProg/pppRyjMegaPlace` (2)

| Function | Bytes | Score | Notes |
|---|---:|---:|---|
| `func_001A0140` | 796 | 272 |  |
| `func_001A07A8` | 1040 | 356.5 |  |

## `unsplit/seg_0252F8` (2)

| Function | Bytes | Score | Notes |
|---|---:|---:|---|
| `func_00126360` | 1240 | 476 |  |
| `func_001252F8` | 1716 | 583 |  |

## `xgoblin` (1)

| Function | Bytes | Score | Notes |
|---|---:|---:|---|
| `func_0011F8C0` | 72 | 24 | a6 |

## `unsplit/seg_01FD30` (1)

| Function | Bytes | Score | Notes |
|---|---:|---:|---|
| `func_00120438` | 136 | 52 | a2 |

## `xowl` (1)

| Function | Bytes | Score | Notes |
|---|---:|---:|---|
| `func_00122B78` | 592 | 234.5 | a3 |

## `xpackage` (1)

| Function | Bytes | Score | Notes |
|---|---:|---:|---|
| `func_00248340` | 436 | 134 | a4 |

## `xpeanut` (1)

| Function | Bytes | Score | Notes |
|---|---:|---:|---|
| `func_001255F8` | 180 | 60 | a2, a3, a4 |

## `xporcupine` (1)

| Function | Bytes | Score | Notes |
|---|---:|---:|---|
| `func_001011E0` | 712 | 231 | a2 |

## `xtoaster` (1)

| Function | Bytes | Score | Notes |
|---|---:|---:|---|
| `func_001245F0` | 1484 | 512.5 | a6 |

## `xtrumpet` (1)

| Function | Bytes | Score | Notes |
|---|---:|---:|---|
| `func_00111C98` | 176 | 55 | a2, a4 |

## `ppp/xberry` (1)

| Function | Bytes | Score | Notes |
|---|---:|---:|---|
| `func_001A7C40` | 740 | 280.5 | a5 |

## `ppp/eiProg/pppDrawMdlTs` (1)

| Function | Bytes | Score | Notes |
|---|---:|---:|---|
| `pppDrawMdlTsDraw` | 388 | 115.5 | a6 |

## `ppp/eiProg/pppDrawShape` (1)

| Function | Bytes | Score | Notes |
|---|---:|---:|---|
| `pppDrawShapeDraw` | 260 | 77 | a1, a3 |

## `ppp/keProg/pppKeBornRnd` (1)

| Function | Bytes | Score | Notes |
|---|---:|---:|---|
| `pppKeBornRndCalc` | 828 | 277 | a5 |

## `ppp/keProg/pppKeBornRnd4` (1)

| Function | Bytes | Score | Notes |
|---|---:|---:|---|
| `pppKeBornRnd4Calc` | 964 | 341.5 | a6 |

## `ppp/keProg/pppKeShpTail3` (1)

| Function | Bytes | Score | Notes |
|---|---:|---:|---|
| `pppKeShpTail3Calc` | 992 | 58.4 | a3, q1 |

## `ppp/keProg/pppKeTh` (1)

| Function | Bytes | Score | Notes |
|---|---:|---:|---|
| `pppKeThDraw` | 140 | 46 | a2, a3, a5, f1 |

## `ppp/keProg/pppKeThHitBorn` (1)

| Function | Bytes | Score | Notes |
|---|---:|---:|---|
| `pppKeThHitBornCalc` | 512 | 188 | a3 |

## `ppp/ryjProg/pppRyjMegaBirthFilter` (1)

| Function | Bytes | Score | Notes |
|---|---:|---:|---|
| `func_001A55D8` | 2312 | 937.5 | a5 |

## `ppp/ryjProg/pppRyjMegaBirthModel` (1)

| Function | Bytes | Score | Notes |
|---|---:|---:|---|
| `pppRyjMegaBirthModelDraw` | 1072 | 357.5 |  |

## `unsplit/seg_006B18` (1)

| Function | Bytes | Score | Notes |
|---|---:|---:|---|
| `func_00107360` | 1388 | 430.5 |  |

## `unsplit/seg_01C7A8` (1)

| Function | Bytes | Score | Notes |
|---|---:|---:|---|
| `func_0011EAE0` | 164 | 57 | a1 |

## `unsplit/seg_0EDC50` (1)

| Function | Bytes | Score | Notes |
|---|---:|---:|---|
| `func_001EDFB8` | 352 | 110 | a1, a3 |

## Parked (242)

Vector-unit (VU0) code, jump-table functions and traps. Usually need hand-written `__asm__` or a jump-table rodata split before they can match.

| File | Parked | Functions (bytes) |
|---|---:|---|
| `unsplit/seg_03BDE8` | 49 | `func_00162808` (12), `func_001627D0` (24), `func_001627E8` (32), `func_00162878` (40), `func_00162848` (44), `func_00162CD0` (44), `func_00162C20` (60), `func_00149678` (80), `func_0014F600` (88), `func_001772F8` (92), `func_001629E8` (108), `func_00162C5C` (116), `func_00158B88` (236), `func_0016F7B8` (252), `func_00144060` (344), `func_00157C60` (360), `func_00175BE0` (384), `func_00143EB8` (420), `func_0015B098` (460), `func_001519C0` (464), `func_00158EC8` (480), `func_00167D70` (500), `func_0015AE48` (532), `func_00153F88` (540), `func_0017B860` (540), `func_0013EAB0` (580), `func_00145AA0` (580), `func_0015FD20` (600), `func_00164BA8` (600), `func_0015F128` (608), `func_00154E38` (616), `func_0013EE40` (640), `func_00170170` (656), `func_00146C98` (800), `func_0013E638` (832), `func_0013E1F8` (864), `func_00151268` (872), `func_00145CE8` (976), `func_00140960` (1004), `func_0014A4A8` (1004), `func_0015FF78` (1016), `func_00169F28` (1228), `func_00143180` (1244), `func_001550A0` (1424), `func_001655E0` (1812), `func_00169688` (2208), `func_0013CFE8` (2752), `func_001636D0` (4248), `func_001606D0` (4332) |
| `unsplit/seg_132D60` | 32 | `func_002407B0` (96), `func_00237018` (172), `func_00245CD0` (204), `func_00249420` (248), `func_002409E0` (252), `func_00244188` (272), `func_00246320` (276), `func_00246AA8` (288), `func_002455C0` (292), `func_0023C7A0` (296), `func_00237790` (308), `func_002388B8` (312), `func_00238768` (336), `func_00244F28` (360), `func_0023D528` (364), `func_00235D70` (372), `func_00237D48` (372), `func_002378C8` (384), `func_002384E0` (476), `func_00238258` (488), `func_00237B30` (536), `func_00244670` (612), `func_0023DD48` (628), `func_0023D208` (648), `func_00235EE8` (676), `func_00235AB0` (700), `func_00236190` (700), `func_002336F8` (900), `func_00233168` (1132), `func_0023A968` (1384), `func_00234910` (1648), `func_00241D60` (3284) |
| `ppp/draw/draw` | 20 | `func_001AB0D8` (20), `func_001AB0F0` (20), `func_001AB108` (24), `func_001AB120` (24), `func_001AB138` (24), `func_001AB150` (24), `func_001AB168` (24), `func_001AB180` (24), `func_001AB320` (36), `func_001AB270` (44), `func_001AB208` (100), `func_001AB198` (108), `func_001AB2A0` (124), `func_001AC298` (396), `func_001AC4F0` (520), `func_001ABCC8` (572), `func_001ABA80` (584), `func_001AB4B8` (812), `func_001A9280` (820), `func_001A96D0` (1332) |
| `unsplit/seg_0EF950` | 17 | `func_001F4570` (76), `func_001F45E0` (76), `func_001F46B0` (200), `func_001EFFC0` (272), `func_001F5E10` (464), `func_001F0148` (504), `func_001F3A20` (808), `func_001F82B0` (1068), `func_001F0868` (1596), `func_001F1FC8` (1636), `func_001FC750` (1652), `func_00203028` (1888), `func_00215838` (2108), `func_0020C1C8` (2148), `func_001F94F0` (2388), `func_002106B8` (3084), `func_001F5FE0` (8488) |
| `unsplit/seg_0150D8` | 17 | `func_00115758` (332), `func_00117C08` (420), `func_00118060` (460), `func_00118378` (460), `func_0011B9F8` (492), `func_00115408` (500), `func_0011C118` (540), `func_00118EA0` (648), `func_0011C338` (688), `func_0011A410` (792), `func_0011A0A0` (876), `func_00119AD8` (936), `func_0011AB88` (960), `func_00115940` (980), `func_001191C8` (1040), `func_0011B220` (1152), `func_001166E8` (4136) |
| `unsplit/seg_02B2C0` | 12 | `func_001371F0` (172), `func_00130070` (288), `func_0012F700` (360), `func_001323A0` (428), `func_00132A78` (504), `func_00139DA8` (588), `func_0012FCD0` (688), `func_00132790` (740), `func_00138400` (756), `func_001315C0` (804), `func_001342C8` (1104), `func_00133A88` (2108) |
| `ppp/draw/md0` | 8 | `func_001BBB60` (376), `func_001BA340` (6176), `func_001B8AA0` (6276), `func_001B0118` (6832), `func_001B3C00` (7608), `func_001B1BF8` (8180), `op_md_ot8` (12076), `func_001B59C0` (12448) |
| `ppp/pppMngr` | 7 | `func_001838E8` (136), `func_00182C78` (300), `pppSetUp` (312), `func_00184548` (480), `func_00182580` (800), `func_00183EF8` (924), `func_00184728` (1800) |
| `unsplit/seg_0B9B78` | 7 | `func_001BB260` (128), `func_001BADE8` (284), `func_001BD880` (360), `func_001BD9E8` (368), `func_001BD470` (900), `func_001BC530` (976), `func_001BC900` (1040) |
| `unsplit/seg_11AC38` | 6 | `func_0021B6A0` (336), `func_00223EA8` (388), `func_0022CDE8` (592), `func_0021D348` (1276), `func_0022A698` (2988), `func_00225EA8` (8268) |
| `unsplit/seg_14B9A8` | 6 | `func_0024E0E4` (12), `func_0024E0A4` (64), `func_0024E18C` (68), `func_0024AB00` (156), `func_0024EDF0` (408), `func_0024E1D0` (1136) |
| `xhumungus` | 5 | `func_001DC2A0` (192), `func_001CCC48` (672), `func_001DC5E8` (700), `func_001CE1A0` (1432), `func_001DE7C0` (1588) |
| `xnoodle` | 3 | `func_0010A2F0` (428), `func_0010B810` (760), `func_0010A4A0` (2224) |
| `unsplit/seg_0252F8` | 3 | `func_00125BB8` (316), `func_00126C10` (624), `func_00125DC8` (828) |
| `ppp/ryjProg/pppRyjDrawMatrixWorldDttFr` | 3 | `func_001A3F98` (72), `func_001A4538` (320), `func_001A4680` (1296) |
| `ppp/ryjProg/pppRyjDrawShipoly` | 3 | `func_0019C460` (440), `pppRyjDrawShipolyCalc` (668), `func_0019C770` (2332) |
| `ppp/ryjProg/pppRyjDrawShipolyBone` | 3 | `func_0019E520` (848), `func_0019D100` (912), `func_0019D898` (3140) |
| `unsplit/seg_001970` | 3 | `func_00104CF8` (152), `func_001054D0` (572), `func_00106000` (968) |
| `xbuffalo` | 2 | `func_001C1B40` (196), `func_001C1680` (436) |
| `unsplit/seg_021B98` | 2 | `func_00121F6C` (88), `func_001223B0` (96) |
| `xsauce` | 2 | `func_0010C360` (344), `func_0010D250` (3968) |
| `ppp/xpear` | 2 | `func_001A87A8` (1184), `func_001A8C48` (1592) |
| `ppp/draw/global` | 2 | `op_random_p` (60), `op_random` (72) |
| `ppp/ryjProg/pppRyjMegaPlaceLamp` | 2 | `func_001A1F28` (1176), `func_001A0F58` (3996) |
| `unsplit/seg_01C7A8` | 2 | `func_0011DE90` (820), `func_0011D7E0` (880) |
| `unsplit/seg_0DDC78` | 2 | `func_001E9670` (356), `func_001E6F28` (768) |
| `xarcade` | 1 | `func_00109580` (1376) |
| `xblade` | 1 | `func_00113E98` (1408) |
| `xpeanut` | 1 | `func_001251B0` (500) |
| `xpotato` | 1 | `func_00217B00` (2884) |
| `xrodent` | 1 | `func_002197E8` (3228) |
| `xtailor` | 1 | `func_0010FEC0` (316) |
| `ppp/xberry` | 1 | `func_001A76E8` (1244) |
| `ppp/eiProg/pppPointRAp` | 1 | `pppPointRApCalc` (588) |
| `ppp/keProg/pppKeLnsFls` | 1 | `func_00194350` (1200) |
| `ppp/keProg/pppKeMdlDtt` | 1 | `pppKeMdlDttDraw` (2540) |
| `ppp/keProg/pppKeShpTail` | 1 | `pppKeShpTailDraw` (1724) |
| `ppp/keProg/pppKeShpTail2` | 1 | `pppKeShpTail2Draw` (1572) |
| `ppp/keProg/pppKeShpTail2X` | 1 | `pppKeShpTail2XDraw` (1644) |
| `ppp/keProg/pppKeShpTail3` | 1 | `pppKeShpTail3Draw` (2012) |
| `ppp/keProg/pppKeShpTail3X` | 1 | `pppKeShpTail3XDraw` (2084) |
| `ppp/keProg/pppKeShpTailX` | 1 | `pppKeShpTailXDraw` (1756) |
| `ppp/ryjProg/pppRyjDrawKekoto` | 1 | `pppRyjDrawKekotoDraw` (2688) |
| `ppp/ryjProg/pppRyjMatrixNoRot` | 1 | `func_0019B698` (1992) |
| `ppp/ryjProg/pppRyjMegaBirthFilter` | 1 | `func_001A6040` (1608) |
| `ppp/ryjProg/pppRyjMegaPlace` | 1 | `func_001A0460` (840) |
| `unsplit/seg_006B18` | 1 | `func_00107AB8` (396) |
| `unsplit/seg_0C45E8` | 1 | `func_001C48C8` (1220) |
