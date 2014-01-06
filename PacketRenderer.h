#ifndef PACKET_RENDERER_HH__
#define PACKET_RENDERER_HH__

#include <QColor>
#include <QGraphicsItem>
#include <QList>
#include <QObject>
#include <QString>

#include <pcap/pcap.h>

class PacketRenderer : public QObject
{
  Q_OBJECT

public:
  PacketRenderer( const QString& colourFile,
                  bool useLogScaling,
                  QObject* parent = 0 );

  virtual ~PacketRenderer();

  void setPacketWidth( float width );
  void setPacketHeight( float height );

  void setMTU( int mtu );

  QGraphicsItem* render( qreal x, qreal y,
                         const pcap_pkthdr* packetHeader,
                         const uchar* packetData ) const;

private:

  bool _useLogScaling;

  float _packetWidth;
  float _packetHeight;

  int _mtu;

  QColor getColour( float value ) const;
  QList<QColor> _colours;
};

#endif
