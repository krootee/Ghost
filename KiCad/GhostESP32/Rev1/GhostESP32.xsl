<?xml version="1.0" encoding="UTF-8"?>
  <xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform">

  <xsl:output method="html" />
  <xsl:template match="/">
    <html>
      <body style='font-family: Helvetica;'>
        <h2>Bill of materials</h2>
        <h1><xsl:value-of select="export/design/sheet/title_block/title"/></h1>
<table>
  <tr><th>Value</th><th>Footprint</th></tr>
        <xsl:for-each select="export/components/comp">
          <tr>
            <td><xsl:value-of select="value" /></td>
            <td><xsl:value-of select="footprint" /></td>
          </tr>
        </xsl:for-each>
      </table>
      </body>
    </html>
  </xsl:template>
</xsl:stylesheet>
