import mysql.connector
from mysql.connector import Error
import sys

__database_name__ = "splashy"
__table_name__ = "your_table"

class DatabaseConnectionManager:
    def __init__(self):
        try:
            self.db = mysql.connector.connect(
                host="localhost",
                user="root",
                passwd="root",
                database=__database_name__
            )
            if self.db.is_connected():
                print("Connected to MariaDB")
        except Error as e:
            print("Error while connecting to MariaDB", e)
            sys.exit(1)
    
    def getTopK(self, k):
        cursor = self.db.cursor()
        select_query = f"SELECT name FROM {__table_name__} ORDER BY quantity DESC LIMIT %s"
        cursor.execute(select_query, (k,))
        rows = cursor.fetchall()
        return [row[0] for row in rows]

    def updateDB(self, id, name, quantity):
        cursor = self.db.cursor()
        select_query = f"SELECT quantity FROM {__table_name__} WHERE id = %s"
        cursor.execute(select_query, (id,))
        row = cursor.fetchone()
        if row is None:
            # ID not found, insert a new row
            insert_query = f"INSERT INTO {__table_name__} (id, name, quantity) VALUES (%s, %s, %s)"
            cursor.execute(insert_query, (id, name, quantity))
        else:
            # ID found, update the row
            new_quantity = quantity + row[0]
            update_query = f"UPDATE {__table_name__} SET name = %s, quantity = %s WHERE id = %s"
            cursor.execute(update_query, (name, new_quantity, id))
        self.db.commit()
    
    def getTotalQuantity(self):
        cursor = self.db.cursor()
        select_query = f"SELECT SUM(quantity) FROM {__table_name__}"
        cursor.execute(select_query)
        total_quantity = cursor.fetchone()[0]
        return total_quantity if total_quantity else 0
    
    # To be called once per month
    def deleteTable(self):
        cursor = self.db.cursor()
        delete_query = f"DELETE FROM {__table_name__}"
        cursor.execute(delete_query)
        self.db.commit()