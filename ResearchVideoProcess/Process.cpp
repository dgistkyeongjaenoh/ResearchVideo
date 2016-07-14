#include <iostream>
#include <allheaders.h>
#include <baseapi.h>

using namespace std;
using namespace tesseract;

#pragma comment(lib, "liblept168")
#pragma comment(lib, "libtesseract302")
#pragma comment (lib, "iconv.lib")

int main()
{
	char *outText;

	TessBaseAPI *api = new TessBaseAPI();
	if (api->Init(NULL, "kor")){
		fprintf(stderr, "Could not\n");
		exit(1);
	}

	Pix *image = pixRead("C:\\a.png");
	api->SetImage(image);

	outText = api->GetUTF8Text();
	printf("OCR output:\n%s", outText);

	FILE*fp = fopen("C:\\a.txt", "wb");
	fputs(outText, fp);
	fclose(fp);

	api->End();
	delete[] outText;
	pixDestroy(&image);

	return 0;
}