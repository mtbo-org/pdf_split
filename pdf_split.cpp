/*
   Source File : PDFCopyingContextTest.cpp


   Copyright 2011 Gal Kahana PDFWriter

   Licensed under the Apache License, Version 2.0 (the "License");
   you may not use this file except in compliance with the License.
   You may obtain a copy of the License at

       http://www.apache.org/licenses/LICENSE-2.0

   Unless required by applicable law or agreed to in writing, software
   distributed under the License is distributed on an "AS IS" BASIS,
   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
   See the License for the specific language governing permissions and
   limitations under the License.


*/
#include <PDFWriter/PDFWriter.h>
#include <PDFWriter/PDFDocumentCopyingContext.h>

#include <iostream>


using namespace std;
using namespace PDFHummus;

int main(int argc, char* argv[])
{
    EStatusCode status;
    PDFWriter pdfWriter;
    PDFDocumentCopyingContext* copyingContext = NULL;

    do
    {
        status = pdfWriter.StartPDF(
            "out.pdf", ePDFVersion13, LogConfiguration(true, true,
                "PDFCopyingContextTest.txt"));
        if (status != PDFHummus::eSuccess)
        {
            cout << "failed to start PDF\n";
            break;
        }


        copyingContext = pdfWriter.CreatePDFCopyingContext(
            "1.pdf");
        if (!copyingContext)
        {
            cout << "failed to initialize copying context from pdf_split\n";
            status = PDFHummus::eFailure;
            break;
        }

        EStatusCodeAndObjectIDType result = copyingContext->AppendPDFPageFromPDF(0);
        if (result.first != PDFHummus::eSuccess)
        {
            cout << "failed to append page 0 from 1.pdf\n";
            status = result.first;
            break;
        }

        copyingContext->End(); // delete will call End() as well...so can avoid

        delete copyingContext;
        copyingContext = NULL;

        status = pdfWriter.EndPDF();
        if (status != PDFHummus::eSuccess)
        {
            cout << "failed in end PDF\n";
            break;
        }

    } while (false);

    delete copyingContext;
    return status == eSuccess ? 0 : 1;
}
