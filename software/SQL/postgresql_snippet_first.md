## 1. Connection refused (0x0000274D/10061)
[引用](链接网址 "https://www.postgresql.org/message-id/DCDDF9A40AB945B8841EC648D1BF5323@Elaborazione1")

> Good morning to everybody
>
>
>
>I have a pg9 db to wich i can connect to by local but not from remote. In >the properties of the postgres db , the port is set to 5300 (not the >default 5432).
>I tried to connect in remote with pgadmin3 and quantum gis, both give the >error Connection refused (0x0000274D/10061).
>This is the complet message in quantum gis (but is silimar in pgadmin3)
>
>
>
>"could not connect to server: Connection refused (0x0000274D/10061)
>
>
>
>Is the server running on host "95.110.201.74" and accepting
>
>
>
>TCP/IP connections on port 5300?"
>
>
>
>Whit both the programs installed on the same pc of the db, i can connect >without problem to the db.
>
>
>
>I already did these settings:
>
>
>
>- in postgresql.conf : listen_addresses = '*' and port = 5300 (in the >place of the default 5432)
>
>
>
>- in pg_hba.conf:  
>
>
>
>host   [dbname]   all     0.0.0.0/0      md5
>
>
>
>host   [dbname]  all      127.0.0.1/32         md5
>
>
>
>- restarted postgres
>
>
>
>I also tried to substitute on the db properties "host=localhost" with >"host=95.110.201.74"
>
>
>
>On the machines are not active firewalls.
>
>
>
>Have you any clue of what's wrong?
>
>
>
>Grazie
>
>
>
>Thanks
>
>