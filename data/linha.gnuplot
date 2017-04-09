 # Inicializacao
clear
reset
set key off

# Configuracoes de saida: inclui formato de exportacao, tamanho do grafico
# fontes utilizadas e nome do arquivo de saida

# Exportacao para o formato .png
set terminal png size 640, 480 enhanced font 'Helvetica, 12'
set output 'linhas.png'

# Exportacao para o formato .jpg
# set terminal jpeg size 640, 480 enhanced font 'Helvetica, 12'
# set output 'histograma.png'

# Exportacao para o formato .svg
# set terminal svg size 640, 480 enhanced background rgb 'white' fname 'Helvetica' fsize 14 butt solid
# set output 'histograma.svg'

# Título do gráfico
set title 'Analise potencial (1994-2014)'

# Configurações do eixo horizontal
set xrange[1994:2014]				# Faixa de valores
set xtics 1							# Salto entre valores
set xtic rotate by -45 scale 0		# Rotação dos rótulos

# Configuração do eixo vertical
set yrange[0:2000]					# Faixa de valores

# Seleção do tipo de gráfico a ser gerado (linha)
# set style data histogram
# set style histogram clustered gap 1
# set style fill solid border -1 			# Preenchimento e contorno
# set linetype 1 lc rgb 'green'			# Cor
# set boxwidth 0.6						# Largura das barras verticais


# Plotagem do gráfico
# Os dados a serrem plotados constam no arquivo extra.dat
plot for [n=2:10] 'extra.dat' u 1:(column(n)) w lines ls n lw 2 smooth csplines