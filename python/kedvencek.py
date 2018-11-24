kedvencek = { "Peti": ["kutya", "macska", "aranyhal"],
              "Sanyi": ["horcsog"],
              "Bogi": ["macska", "lo"],
              "Moricka": ["kutya", "aranyhal"],
              "Niki": ["nyul", "macska"] }


def van_e(gyerek, allat):
    if gyerek in kedvencek and allat in kedvencek[gyerek]:
        return True
    return False


def kiknek_van(allat):
    l = []
    for gyerek in kedvencek:
        if allat in kedvencek[gyerek]:
            l.append(gyerek)
    return l

def kiknek_van2(allat):
    return [gyerek for gyerek in kedvencek if allat in kedvencek[gyerek]]


def osszes_allat():
   a = []
   for lista in kedvencek.values():
       for allat in lista:
           a.append(allat)
   return set(a)

def osszes_allat2():
 a = [allat for lista in kedvencek.values() for allat in lista]
 return set(a)


print(kedvencek.keys())
print(list(kedvencek.keys()))

for gyerek in kedvencek:
    print(gyerek)

for gyerek in kedvencek.keys():
    print(gyerek)

for lista in kedvencek.values():
    print(lista)

for gyerek, lista in kedvencek.items():
    print(gyerek, lista)

print("Peti kedvencei: ", kedvencek["Peti"])

print("Petinek van kutyaja: ", van_e("Peti", "kutya"))
print("Locinak van aranyhala: ", van_e("Loci", "aranyhal"))
print("Sanyinak van horcsoge: ", van_e("Sanyi", "horcsog"))

print(kiknek_van("macska"))
print(kiknek_van2("macska"))

print(osszes_allat())
print(osszes_allat2())
