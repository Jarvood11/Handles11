Хен­длы (они же дес­крип­торы) в Windows — это один из важ­ных кам­ней в фун­дамен­те сис­темы. На хен­длах пос­тро­ено и осно­выва­ется 
все вза­имо­дей­ствие из прог­рам­мно­го кода с ком­понен­тами Windows. Имен­но бла­года­ря дес­крип­торам ядро понима­ет, к какому объ­екту
мы хотим обра­тить­ся и с каким уров­нем дос­тупа. Хендл обыч­но мож­но получить с помощью стан­дар­тных фун­кций.
На файл — через CreateFile(), на LSA — через LsaOpenPolicy(). В Windows очень мно­го раз­ных объ­ектов, с которы­ми 
мож­но вза­имо­дей­ство­вать. Ты можешь открыть спи­сок WinAPI, ткнуть на любой инте­ресу­ющий ком­понент и убе­дить­ся, 
что самой основной и важ­ной апи­хой будет API для получе­ния хен­дла на нуж­ный объ­ект. Не получил хендл — не смог вза­имо­дей­ство­вать с сис­темой.