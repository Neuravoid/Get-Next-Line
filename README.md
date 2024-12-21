# Get Next Line

**Get Next Line**, 42 okullarının müfredatında yer alan bir projedir. Bu proje, bir dosya tanıtıcısından satır satır veri okumayı sağlayan bir C fonksiyonunun geliştirilmesini amaçlar.

## Proje Amacı

Bu projenin temel amacı, aşağıdaki özelliklere sahip bir `get_next_line` fonksiyonunu yazmaktır:

- **Satır Okuma**: Fonksiyon, her çağrıldığında bir dosya tanıtıcısından bir satır okur ve bu satırı döndürür.
- **Bellek Yönetimi**: `malloc` ve `free` fonksiyonlarını kullanarak dinamik bellek tahsisi ve yönetimi yapılır.
- **Sistem Çağrıları**: `read` sistem çağrısı kullanılarak dosyadan veri okunur.
- **Statik Değişkenler**: Fonksiyon, bir önceki çağrısından kalan verileri saklamak için statik değişkenler kullanır.

## Fonksiyon Prototipi

```c
char *get_next_line(int fd);
```

- `fd`: Okunacak dosya tanıtıcısı.
- **Dönen Değer**: Okunan satırı içeren bir karakter işaretçisi. Dosyanın sonuna gelinmişse veya bir hata oluşmuşsa `NULL` döner.

## Kullanım

`get_next_line` fonksiyonu, bir döngü içinde çağrılarak dosyanın sonuna kadar her seferinde bir satır okunabilir:

```c
int fd = open("dosya.txt", O_RDONLY);
char *satir;

while ((satir = get_next_line(fd)) != NULL)
{
    // Satırı işle
    free(satir);
}
close(fd);
```

## Derleme

Fonksiyon, derleme sırasında `BUFFER_SIZE` makrosu tanımlanarak farklı tampon boyutlarıyla test edilebilir:

```bash
gcc -Wall -Wextra -Werror -D BUFFER_SIZE=32 get_next_line.c get_next_line_utils.c -o gnl
```

## Dikkate Alınması Gerekenler

- **Tampon Boyutu**: `BUFFER_SIZE` değeri, `read` çağrılarında kullanılacak tampon boyutunu belirler ve performansı etkileyebilir.
- **Çoklu Dosya Tanıtıcıları**: Fonksiyon, aynı anda birden fazla dosya tanıtıcısından okuma yapacak şekilde tasarlanmalıdır.
- **Bellek Sızıntıları**: Dinamik bellek tahsisi yapıldığından, bellek sızıntılarını önlemek için her okunan satırın serbest bırakılması önemlidir.

## Lisans

Bu proje, MIT Lisansı ile lisanslanmıştır. Daha fazla bilgi için `LICENSE` dosyasına bakınız.
