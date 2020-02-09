from db_utils import *

# school DB
create_db()

# student TABLE
create_table()

insert_student('cupjoo@naver.com', 'aaa')
select_student('cupjoo@naver.com')
update_email('new@naver.com', 'cupjoo@naver.com')
delete_student('new@naver.com')