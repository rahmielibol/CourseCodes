
# Yapay Sinir Aglari dersi ornek perceptron kodu
# Ornek üzerinden gosterilecekler:
# Veri sayisinin YSA agini egitme sureci
# Test verisinin, egitim verisinden az alindiginda ortaya cikabilecek durumlar
# Ogrenme hizinin egitim surecine etkisi ve yapilan yanlisi duzeltme hizi (0.001)
# Agirliklar buyuk alinirsa egitim hizi ve hata 
# Verinin birbirine ne kadar yakin oldugunun egitime etkisi 




from pylab import rand,plot,norm
import matplotlib.pyplot as plt
import numpy as np




print("Basla")

egitim_verisi = 20
test_verisi = int(egitim_verisi*.5)

class Perceptron:
	def __init__(self):


		print("Agirliklar [-1,1] araliginda rastgele belirlendi.")
		self.w = rand(3)*2-1
		print(self.w)
        
		self.ogrenme_Hizi = .5



					

	def veri_Uretimi(n):
		"""
		2 boyutlu lineer ayrıştırılabilir n tane ornek iceren veri seti olusturur. 
        Ornek verideki 3. bilgi (x[2]) bias degeri (+1), 4. bilgi (x[3]) ornegin etiketidir.
		"""

		bias=1            
		print('Datalar olusturuluyor.')            


		xb = (rand(n)-1)
		yb = (rand(n))
		xr = (rand(n))
		yr = (rand(n)-1)
		inputs = []
		plt.Figure()
		for i in range(len(xb)):
			inputs.append([xb[i],yb[i],bias,1])
			plt.plot(xb[i],yb[i],'ob')
			inputs.append([xr[i],yr[i],bias,-1])
			plt.plot(xr[i],yr[i],'or')

		print(inputs)
		plt.title('Uretilen veriler')
		plt.axhline(y=0,color='k')
		plt.axvline(x=0,color='k')
		plt.show()
		return inputs
		

        

	def cevap_islevi(self,x):
		y = 0
		for i in range(np.size(x)-1):
			y += x[i]*self.w[i]
            
        
		if y >= 0:
			return 1
		else:
			return -1


	def agirlik_Guncelleme(self,x,iterasyon_hatasi):
		"""
		w(t+1) = w(t) + ogrenme_Hizi * iterasyon_hatasi * giris 
        Burada d beklenen cevap (verideki etiket), 
        r perceptron cikisindan elde edilen cevaptir.
		iterasyon hatasi (d-r) ile ifade edilir.
		"""
		print("Agirliklar guncelleniyor.")
		print("Iterasyon hatasi :" + str(iterasyon_hatasi))
		self.w[0] += self.ogrenme_Hizi*iterasyon_hatasi*x[0]
		self.w[1] += self.ogrenme_Hizi*iterasyon_hatasi*x[1]
		self.w[2] += self.ogrenme_Hizi*iterasyon_hatasi*x[2]
		print(self.w)
		                

	def Egitim(self,data):
		"""
        Egitim icin alinan datanın her vektoru dort elemandan olusur.
        Vektordeki 4. bilgi (x[3]) ornegin etiketidir (d).
		
		"""
		print(" -----   Egitim basladi ----- ")		
		ogrenmeTamam_karari = False
		dis_iterasyon_sayisi = 0
		list_yanlis_sayisi = []
		while not ogrenmeTamam_karari:
			dis_iterasyon_sayisi += 1
			genelHata = 0.0
			yanlis_siniflandirma_sayisi = 0
			dogru_siniflandirma_sayisi = 0
			ic_iterasyon_sayisi = 0
			for x in data:                        
				ic_iterasyon_sayisi += 1
				print('-------------------------')                
				print('-------------------------')                
				print(dis_iterasyon_sayisi,'. dongunun', ic_iterasyon_sayisi,'. adimi')
				print('-------------------------')                
				print('-------------------------')                
				r = self.cevap_islevi(x)
				print(x, 'noktasi ile egitim yapiliyor.')
				print("response (cevap) = " + str(r))
				print("Istenen cikis = "+ str(x[3]))
				iterasyon_hatasi = x[3] - r
				self.agirlik_Guncelleme(x,iterasyon_hatasi)
				if x[3] != r:
					print(" -------  > Yanlis siniflandirma !!!")
					yanlis_siniflandirma_sayisi += 1
					genelHata += abs(iterasyon_hatasi/2)
					print('iterasyon',ic_iterasyon_sayisi,'hata', genelHata)
					print('dogru_siniflandirma_sayisi', dogru_siniflandirma_sayisi)
					print('yanlis_siniflandirma_sayisi', yanlis_siniflandirma_sayisi)
				else:
					print("*********** ->  dogru siniflandirma")
					dogru_siniflandirma_sayisi += 1
					print('iterasyon',ic_iterasyon_sayisi,'hata', genelHata)                    
					print('dogru_siniflandirma_sayisi', dogru_siniflandirma_sayisi)
					print('yanlis_siniflandirma_sayisi', yanlis_siniflandirma_sayisi)

			list_yanlis_sayisi.append(yanlis_siniflandirma_sayisi)                
			print(dis_iterasyon_sayisi,list_yanlis_sayisi)


			if genelHata == 0.0 or dis_iterasyon_sayisi >= 100:
					print('Ag egitildi ----> iterasyon',dis_iterasyon_sayisi,'Hata',genelHata)
					ogrenmeTamam_karari = True

					plt.Figure()
					plt.plot(range(1,dis_iterasyon_sayisi+1),list_yanlis_sayisi)
					plt.plot([1,dis_iterasyon_sayisi],[0,0],'r')                    

					plt.xlabel('iterasyon sayisi')
					plt.ylabel('hata sayisi')
					plt.show()
                    
                                                         
    
	def test_Sureci(self,data):
		print(" ---- Test basladi ----")
		yanlis_siniflandirilan_veri_sayisi = 0
		test_edilen_veri_sayisi = 0		
		plt.Figure()
		for x in data:
			test_edilen_veri_sayisi += 1
			print(str(x) + ". data test ediliyor.")
			r = self.cevap_islevi(x)
			if r != x[-1]:
				print('Hata !')
				print('Test asamasinda cevap degeri ile beklenen deger farkli cikti!')
				yanlis_siniflandirilan_veri_sayisi += 1
                
			if r == 1:
				plot(x[0],x[1],'ob')
			else:
				plot(x[0],x[1],'or')


		print('Agin test sonucu basari yuzdesi : ', 100*(1-yanlis_siniflandirilan_veri_sayisi/(test_edilen_veri_sayisi)))
		# karar dogrusu, agirlik vektorune dik
		n = norm(self.w)
		ww = self.w/n
		ww1 = [ww[1], -ww[0]]
		ww2 = [-ww[1], ww[0]]

		plt.plot([ww1[0], ww2[0]],[ww1[1], ww2[1]],'m')
		plt.axhline(y=0,color='k')
		plt.axvline(x=0,color='k')        
		plt.title('Test verisi sonucu')
		plt.show()
        
        
        
	

#
	def main(egitim_verisi_sayisi,test_verisi_sayisi):
		egitim_Verisi = Perceptron.veri_Uretimi(egitim_verisi_sayisi)
		ysa = Perceptron()
		ysa.Egitim(egitim_Verisi)
		test_Verisi = Perceptron.veri_Uretimi(test_verisi_sayisi)
		ysa.test_Sureci(test_Verisi)
        
        

        
        
#if __name__ == '__main__':
Perceptron.main(egitim_verisi,test_verisi)
print('Bitti...')
