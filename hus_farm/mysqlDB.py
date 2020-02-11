import pymysql

def db_query(db, sql, params):
    # Connect to MySQL
    conn = pymysql.connect(
        host='192.168.3.17',
        user='java',
        password='java',
        charset='utf8',
        db=db
    )
    try:
        # create Dictionary Cursor
        with conn.cursor() as cursor:
            sql_query = sql
            # excute SQL
            cursor.execute(sql_query, params)
        # commit data
        conn.commit()
    finally:
        conn.close()