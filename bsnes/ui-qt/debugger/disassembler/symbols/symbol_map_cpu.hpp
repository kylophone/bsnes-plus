const char *DEFAULT_SYMBOL_MAP_CPU =
  "; default registers used for CPU\n" \
  "\n" \
  "[labels]; simple labels\n" \
  "00:2100 SNES.INIDISP\n" \
  "00:2101 SNES.OBSEL\n" \
  "00:2102 SNES.OAMADDL\n" \
  "00:2103 SNES.OAMADDH\n" \
  "00:2104 SNES.OAMDATA\n" \
  "00:2105 SNES.BGMODE\n" \
  "00:2106 SNES.MOSAIC\n" \
  "00:2107 SNES.BG1SC\n" \
  "00:2108 SNES.BG2SC\n" \
  "00:2109 SNES.BG3SC\n" \
  "00:210A SNES.BG3SC\n" \
  "00:210B SNES.BG12NBA\n" \
  "00:210C SNES.BG34NBA\n" \
  "00:210D SNES.BG1HOFS\n" \
  "00:210E SNES.BG1VOFS\n" \
  "00:210F SNES.BG2HOFS\n" \
  "00:2110 SNES.BG2VOFS\n" \
  "00:2111 SNES.BG3HOFS\n" \
  "00:2112 SNES.BG3VOFS\n" \
  "00:2113 SNES.BG4HOFS\n" \
  "00:2114 SNES.BG4VOFS\n" \
  "00:2115 SNES.VMAIN\n" \
  "00:2116 SNES.VMADDL\n" \
  "00:2117 SNES.VMADDH\n" \
  "00:2118 SNES.VMDATAL\n" \
  "00:2119 SNES.VMDATAH\n" \
  "00:211A SNES.M7SEL\n" \
  "00:211B SNES.M7A\n" \
  "00:211C SNES.M7B\n" \
  "00:211D SNES.M7C\n" \
  "00:211E SNES.M7D\n" \
  "00:211F SNES.M7X\n" \
  "00:2120 SNES.M7Y\n" \
  "00:2121 SNES.CGADD\n" \
  "00:2122 SNES.CGDATA\n" \
  "00:2123 SNES.W12SEL\n" \
  "00:2124 SNES.W34SEL\n" \
  "00:2125 SNES.WOBJSEL\n" \
  "00:2126 SNES.WH0\n" \
  "00:2127 SNES.WH1\n" \
  "00:2128 SNES.WH2\n" \
  "00:2129 SNES.WH3\n" \
  "00:212A SNES.WBGLOG\n" \
  "00:212B SNES.WOBJLOG\n" \
  "00:212C SNES.TM\n" \
  "00:212D SNES.TS\n" \
  "00:212E SNES.TMW\n" \
  "00:212F SNES.TSW\n" \
  "00:2130 SNES.CGWSEL\n" \
  "00:2131 SNES.CGADSUB\n" \
  "00:2132 SNES.COLDATA\n" \
  "00:2133 SNES.SETINI\n" \
  "00:2134 SNES.MPYL\n" \
  "00:2135 SNES.MPYM\n" \
  "00:2136 SNES.MPYH\n" \
  "00:2137 SNES.SLHV\n" \
  "00:2138 SNES.OAMDATAREAD\n" \
  "00:2139 SNES.VMDATALREAD\n" \
  "00:213A SNES.VMDATAHREAD\n" \
  "00:213B SNES.CGDATAREAD\n" \
  "00:213C SNES.OPHCT\n" \
  "00:213D SNES.OPVCT\n" \
  "00:213E SNES.STAT77\n" \
  "00:213F SNES.STAT78\n" \
  "00:2140 SNES.APUIO0\n" \
  "00:2141 SNES.APUIO1\n" \
  "00:2142 SNES.APUIO2\n" \
  "00:2143 SNES.APUIO3\n" \
  "00:2180 SNES.WMDATA\n" \
  "00:2181 SNES.WMADDL\n" \
  "00:2182 SNES.WMADDM\n" \
  "00:2183 SNES.WMADDH\n" \
  "00:4016 SNES.JOYSER0\n" \
  "00:4017 SNES.JOYSER1\n" \
  "00:4200 SNES.NMITIMEN\n" \
  "00:4201 SNES.WRIO\n" \
  "00:4202 SNES.WRMPYA\n" \
  "00:4203 SNES.WRMPYB\n" \
  "00:4204 SNES.WRDIVL\n" \
  "00:4205 SNES.WRDIVH\n" \
  "00:4206 SNES.WRDIVB\n" \
  "00:4207 SNES.HTIMEL\n" \
  "00:4208 SNES.HTIMEH\n" \
  "00:4209 SNES.VTIMEL\n" \
  "00:420A SNES.VTIMEH\n" \
  "00:420B SNES.MDMAEN\n" \
  "00:420C SNES.HDMAEN\n" \
  "00:420D SNES.MEMSEL\n" \
  "00:4210 SNES.RDNMI\n" \
  "00:4211 SNES.TIMEUP\n" \
  "00:4212 SNES.HVBJOY\n" \
  "00:4213 SNES.RDIO\n" \
  "00:4214 SNES.RDDIVL\n" \
  "00:4215 SNES.RDDIVH\n" \
  "00:4216 SNES.RDMPYL\n" \
  "00:4217 SNES.RDMPYH\n" \
  "00:4218 SNES.JOY1L\n" \
  "00:4219 SNES.JOY1H\n" \
  "00:421A SNES.JOY2L\n" \
  "00:421B SNES.JOY2H\n" \
  "00:421C SNES.JOY3L\n" \
  "00:421D SNES.JOY3H\n" \
  "00:421E SNES.JOY4L\n" \
  "00:421F SNES.JOY4H\n" \
  "00:4300 SNES.DMAP0\n" \
  "00:4301 SNES.BBAD0\n" \
  "00:4302 SNES.A1T0L\n" \
  "00:4303 SNES.A1T0H\n" \
  "00:4304 SNES.A1B0\n" \
  "00:4305 SNES.DAS0L\n" \
  "00:4306 SNES.DAS0H\n" \
  "00:4307 SNES.DASB0\n" \
  "00:4308 SNES.A2A0L\n" \
  "00:4309 SNES.A2A0H\n" \
  "00:430A SNES.NTLR0\n" \
  "00:4310 SNES.DMAP1\n" \
  "00:4311 SNES.BBAD1\n" \
  "00:4312 SNES.A1T1L\n" \
  "00:4313 SNES.A1T1H\n" \
  "00:4314 SNES.A1B1\n" \
  "00:4315 SNES.DAS1L\n" \
  "00:4316 SNES.DAS1H\n" \
  "00:4317 SNES.DASB1\n" \
  "00:4318 SNES.A2A1L\n" \
  "00:4319 SNES.A2A1H\n" \
  "00:431A SNES.NTLR1\n" \
  "00:4320 SNES.DMAP2\n" \
  "00:4321 SNES.BBAD2\n" \
  "00:4322 SNES.A1T2L\n" \
  "00:4323 SNES.A1T2H\n" \
  "00:4324 SNES.A1B2\n" \
  "00:4325 SNES.DAS2L\n" \
  "00:4326 SNES.DAS2H\n" \
  "00:4327 SNES.DASB2\n" \
  "00:4328 SNES.A2A2L\n" \
  "00:4329 SNES.A2A2H\n" \
  "00:432A SNES.NTLR2\n" \
  "00:4330 SNES.DMAP3\n" \
  "00:4331 SNES.BBAD3\n" \
  "00:4332 SNES.A1T3L\n" \
  "00:4333 SNES.A1T3H\n" \
  "00:4334 SNES.A1B3\n" \
  "00:4335 SNES.DAS3L\n" \
  "00:4336 SNES.DAS3H\n" \
  "00:4337 SNES.DASB3\n" \
  "00:4338 SNES.A2A3L\n" \
  "00:4339 SNES.A2A3H\n" \
  "00:433A SNES.NTLR3\n" \
  "00:4340 SNES.DMAP4\n" \
  "00:4341 SNES.BBAD4\n" \
  "00:4342 SNES.A1T4L\n" \
  "00:4343 SNES.A1T4H\n" \
  "00:4344 SNES.A1B4\n" \
  "00:4345 SNES.DAS4L\n" \
  "00:4346 SNES.DAS4H\n" \
  "00:4347 SNES.DASB4\n" \
  "00:4348 SNES.A2A4L\n" \
  "00:4349 SNES.A2A4H\n" \
  "00:434A SNES.NTLR4\n" \
  "00:4350 SNES.DMAP5\n" \
  "00:4351 SNES.BBAD5\n" \
  "00:4352 SNES.A1T5L\n" \
  "00:4353 SNES.A1T5H\n" \
  "00:4354 SNES.A1B5\n" \
  "00:4355 SNES.DAS5L\n" \
  "00:4356 SNES.DAS5H\n" \
  "00:4357 SNES.DASB5\n" \
  "00:4358 SNES.A2A5L\n" \
  "00:4359 SNES.A2A5H\n" \
  "00:435A SNES.NTLR5\n" \
  "00:4360 SNES.DMAP6\n" \
  "00:4361 SNES.BBAD6\n" \
  "00:4362 SNES.A1T6L\n" \
  "00:4363 SNES.A1T6H\n" \
  "00:4364 SNES.A1B6\n" \
  "00:4365 SNES.DAS6L\n" \
  "00:4366 SNES.DAS6H\n" \
  "00:4367 SNES.DASB6\n" \
  "00:4368 SNES.A2A6L\n" \
  "00:4369 SNES.A2A6H\n" \
  "00:436A SNES.NTLR6\n" \
  "00:4370 SNES.DMAP7\n" \
  "00:4371 SNES.BBAD7\n" \
  "00:4372 SNES.A1T7L\n" \
  "00:4373 SNES.A1T7H\n" \
  "00:4374 SNES.A1B7\n" \
  "00:4375 SNES.DAS7L\n" \
  "00:4376 SNES.DAS7H\n" \
  "00:4377 SNES.DASB7\n" \
  "00:4378 SNES.A2A7L\n" \
  "00:4379 SNES.A2A7H\n" \
  "00:437A SNES.NTLR7\n" \
  "\n" \
  "[definitions]\n" \
  "00000000 test\n" \
  "00000000 test\n" \
  "00000000 test\n" \
;
