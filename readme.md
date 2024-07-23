Warehouse Inventory Application
This is a Warehouse Inventory application developed using Qt C++. It allows users to manage inventory items, view and edit data stored in a SQLite database, and generate PDF reports.

Features:
Table View in Tab 1: Displays inventory items from the SQLite database.
Add, remove, and modify items directly in the table view.
Changes are reflected in the SQLite database.
Generate PDF Report: A button to generate a PDF report of the current inventory.
Generates a CSV file and then converts it to a PDF file using a Python script.
PDF Viewer in Tab 2: Displays the generated PDF report.
Automatically updates to show the latest generated PDF when switching to Tab 2.

Requirements:
Qt 6.7.2 or later
Python 3.x
reportlab library for Python
SQLite database

Build and Run the Application:
Open the project in Qt Creator and build it using qmake. Then, run the application.

