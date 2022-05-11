import requests
from bs4 import BeautifulSoup

url = 'https://computer.hufs.ac.kr/ces/882/subview.do'

r = requests.get(url)

html = r.text
soup = BeautifulSoup(html, 'html.parser')
'''for link in soup.find_all('a'):
    print(link.get('href'))
print(r.status_code)
print(r.headers['Content-Type'])
print(r.encoding)
print(r.ok)
'''
titles_html = soup.select('.td.td-subject > a > strong')
print(titles_html)
for i in range(len(titles_html)):
    print(i+1, titles_html[i].text)


