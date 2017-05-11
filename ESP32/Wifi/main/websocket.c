void ws_server(void *pvParameters) {
 //connection references
 struct netconn *conn, *newconn;

 //set up new TCP listener
 conn = netconn_new(NETCONN_TCP);
 netconn_bind(conn, NULL, 9998);
 netconn_listen(conn);

 //wait for connections
 while (netconn_accept(conn, &newconn) == ERR_OK)
 ws_server_netconn_serve(newconn);

 //close connection
 netconn_close(conn);
 netconn_delete(conn);
}
