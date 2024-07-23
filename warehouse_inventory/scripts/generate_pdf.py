import csv
from reportlab.lib import colors
from reportlab.lib.pagesizes import A4
from reportlab.platypus import SimpleDocTemplate, Table, TableStyle

#from datetime import date
#import os

def generate_pdf_from_csv(csv_file_path, pdf_file_path):
    data = []
    with open(csv_file_path, newline='', encoding='utf-8') as csvfile:
        reader = csv.reader(csvfile)
        for row in reader:
            data.append(row)
    
    pdf = SimpleDocTemplate(pdf_file_path, pagesize=A4)
    table = Table(data)
    
    style = TableStyle([
        ('BACKGROUND', (0, 0), (-1, 0), colors.grey),
        ('TEXTCOLOR', (0, 0), (-1, 0), colors.whitesmoke),
        ('ALIGN', (0, 0), (-1, -1), 'CENTER'),
        ('FONTNAME', (0, 0), (-1, 0), 'Helvetica-Bold'),
        ('BOTTOMPADDING', (0, 0), (-1, 0), 12),
        ('BACKGROUND', (0, 1), (-1, -1), colors.white),
        ('GRID', (0, 0), (-1, -1), 1, colors.black),
    ])
    
    table.setStyle(style)
    elems = []
    elems.append(table)
    pdf.build(elems)

if __name__ == "__main__":
    #today = date.today()

    csv_file_path = "D:/Qt/warehouse_inventory-master/warehouse_inventory-master/temp/table_view_data.csv"
    pdf_file_path = "D:/Qt/warehouse_inventory-master/warehouse_inventory-master/reports/raport_stoc_curent.pdf"
    generate_pdf_from_csv(csv_file_path, pdf_file_path)

