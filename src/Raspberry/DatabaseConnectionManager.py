import mysql.connector
from mysql.connector import Error
import sys
import threading

__database_name__ = "splashy"
__table_name__ = "splashy_table"

class DatabaseConnectionManager:
    def __init__(self):
        try:
            self.db = mysql.connector.connect(
                host="localhost",
                user="root",
                passwd="splashy_group_3",
                database=__database_name__
            )
            if self.db.is_connected():
                print("Connected to MariaDB")
            self.lock = threading.Lock()
        except Error as e:
            print("Error while connecting to MariaDB", e)
            sys.exit(1)
        self.liters_montly_goal = 5600     # 5600 liters per month is the goal for the water consumption
        self.water_plasic_ratio = 0.03   # 0.03 kilograms of plastic per liter of water
    
    def __getTopK__(self, k):
        with self.lock:
            cursor = self.db.cursor()
            select_query = f"SELECT name, quantity FROM {__table_name__} WHERE id != 'None' ORDER BY quantity DESC LIMIT %s"
            cursor.execute(select_query, (k,))
            rows = cursor.fetchall()
            return [(row[0], row[1]) for row in rows]
        
    def getTopK(self, k):
        top_k = self.__getTopK__(k)
        if len(top_k) < k:
            top_k += [("None", 0)] * (k - len(top_k))

    def updateDB(self, id, name, quantity):
        with self.lock:
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
        with self.lock:
            cursor = self.db.cursor()
            select_query = f"SELECT SUM(quantity) FROM {__table_name__}"
            cursor.execute(select_query)
            total_quantity = cursor.fetchone()[0]
            return total_quantity if total_quantity else 0
        
    def getPlasticSaved(self):
        return self.getTotalQuantity() * self.water_plasic_ratio
    
    
    # To be called once per month
    def deleteTable(self):
        with self.lock:
            cursor = self.db.cursor()
            delete_query = f"DELETE FROM {__table_name__}"
            cursor.execute(delete_query)
            self.db.commit()
